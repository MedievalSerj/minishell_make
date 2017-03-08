/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_root_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:25:31 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/03 16:25:32 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*sub_dot_dot(char *pwd, char *name)
{
	char	*tmp;
	char	*tmp_pwd;

	if (ft_char_last_n(pwd, '/') == 0)
		pwd = ft_reasign(pwd, "/", 0);
	tmp = ft_strsub(name, 3, ft_strlen(name) - 2);
	free(name);
	tmp_pwd = ft_strsub(pwd, 0, (size_t)ft_char_last_n(pwd, '/'));
	free(pwd);
	if (tmp_pwd[0] == '\0')
		tmp_pwd = ft_reasign(tmp_pwd, "/", 0);
	return (sh_get_root_path(tmp, tmp_pwd));
}

static char	*sub_dot(char *pwd, char *name)
{
	char *tmp;

	tmp = ft_strsub(name, 2, ft_strlen(name) - 1);
	free(name);
	return (sh_get_root_path(tmp, pwd));
}

static char	*sub_join(char *pwd, char *name)
{
	char *path;

	if (ft_strequ(pwd, "/"))
		return (ft_str_j(pwd, name, 3));
	else if (name[0] != '\0')
	{
		path = ft_str_j(pwd, "/", 1);
		path = ft_str_j(path, name, 3);
	}
	else
	{
		free(name);
		path = pwd;
	}
	return (path);
}

char		*sh_get_root_path(char *name, char *pwd)
{
	char *path;

	if (!name)
		return (ft_strnew(2));
	if (!pwd)
		pwd = getcwd(NULL, 0);
	if (ft_strnequ(name, "./", 2))
		path = sub_dot(pwd, name);
	else if (ft_strnequ(name, "../", 3) || ft_strequ(name, ".."))
		path = sub_dot_dot(pwd, name);
	else
		path = sub_join(pwd, name);
	return (path);
}
