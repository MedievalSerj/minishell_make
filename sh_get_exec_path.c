/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_exec_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:13:05 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/19 15:13:13 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**sh_get_paths(t_lst *env)
{
	char	*tmp;
	char	**paths;

	if (!(tmp = sh_get_val("PATH", env)))
		return (NULL);
	paths = ft_strsplit(tmp, ':');
	ft_strdel(&tmp);
	return (paths);
}

static char	*validate_path(char *path, char *relative)
{
	t_info	*info;
	char	*exec_path;

	exec_path = NULL;
	if (!(info = get_info(path)))
		sh_perror("minishell: no such file or directory: ", relative, NULL);
	else if (info->type == 'd')
		sh_perror("minishell: ", relative, ": is a directory");
	else if (info->modes[3] == '-')
		sh_perror("minishell: ", relative, ": Permission denied");
	else
		exec_path = ft_strdup(info->path);
	if (info)
		sh_del_info(&info);
	return (exec_path);
}

static char	*search_exe(char *name, t_lst *env)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	paths = sh_get_paths(env);
	i = -1;
	while (paths && paths[++i])
	{
		path = ft_str_j(paths[i], "/", 0);
		path = ft_str_j(path, name, 1);
		if (access(path, F_OK) == 0)
		{
			if ((tmp = validate_path(path, path)))
			{
				ft_strdel(&path);
				ft_clear_arr(&paths);
				return (tmp);
			}
		}
		ft_strdel(&path);
	}
	sh_perror("minishell: command not found: ", name, NULL);
	ft_clear_arr(&paths);
	return (NULL);
}

char		*sh_get_exec_path(char *name, t_lst *env)
{
	char *path;
	char *tmp;

	if (name[0] == '.')
	{
		tmp = sh_get_root_path(ft_strdup(name), NULL);
		path = validate_path(tmp, name);
		free(tmp);
	}
	else if (name[0] == '/')
		path = validate_path(name, name);
	else
		path = search_exe(name, env);
	return (path);
}
