/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:24:11 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/28 15:24:20 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_path(char *path, char *in_path)
{
	t_info	*info;
	char	*flag;
	int		n;

	flag = NULL;
	if (!(info = get_info(path)))
		sh_perror("minishell: cd: no such file or directory: ", in_path, NULL);
	else if (info->type != 'd')
		sh_perror("minishell: cd: not a directory: ", in_path, NULL);
	else if (info->modes[3] == '-')
		sh_perror("minishell: cd: permission denied: ", in_path, NULL);
	else
		flag = ft_strdup(path);
	if (info)
		sh_del_info(&info);
	if (path)
		free(path);
	if (flag)
	{
		n = ft_strlen(flag);
		if (n > 2 && flag[n - 1] == '/')
			flag[n - 1] = '\0';
	}
	return (flag);
}

static void	sub_cd(char *new_pwd, t_lst **env, char *in_path)
{
	char *old_pwd;

	if (!(old_pwd = getcwd(NULL, 0)))
		return ;
	if (!(new_pwd = check_path(new_pwd, in_path)))
	{
		free(old_pwd);
		return ;
	}
	sh_set_val("OLDPWD", old_pwd, env);
	if (chdir(new_pwd) == -1)
		sh_perror("minishell: cd: no such file or directory: ", in_path, NULL);
	else
		sh_set_val("PWD", new_pwd, env);
	free(new_pwd);
	free(old_pwd);
}

static void	cd_previous(t_lst **env)
{
	t_lst	*tmp;
	t_env	*content;
	char	*old_pwd;

	tmp = *env;
	while (tmp)
	{
		content = (t_env*)tmp->content;
		if (ft_strequ(content->key, "OLDPWD"))
		{
			old_pwd = sh_get_val("OLDPWD", *env);
			sub_cd(old_pwd, env, old_pwd);
			return ;
		}
		tmp = tmp->next;
	}
	sh_perror("minishell: cd: OLDPWD not set", NULL, NULL);
}

void		sh_cd(t_cmd *cmd, t_lst **env)
{
	char *in_path;

	in_path = cmd->options_args[1];
	if (!cmd->options_args[1] || cmd->options_args[1][0] == '\0')
		sub_cd(sh_get_val("HOME", *env), env, in_path);
	else if (ft_strequ(cmd->options_args[1], "-"))
		cd_previous(env);
	else if (ft_strequ(cmd->options_args[1], "."))
		sub_cd(ft_strdup("./"), env, "./");
	else if (cmd->options_args[1][0] == '.')
		sub_cd(sh_get_root_path(ft_strdup(cmd->options_args[1]), NULL), \
		env, in_path);
	else
		sub_cd(ft_strdup(cmd->options_args[1]), env, in_path);
}
