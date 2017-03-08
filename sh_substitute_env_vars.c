/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_substitute_env_vars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:16:23 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/06 12:16:25 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*substitute_env_vars(char *param, t_lst *env, int j)
{
	char *tmp;
	char *name;
	char *val;

	name = ft_strsub(param, j + 1, ft_strlen(&param[j]));
	if ((val = sh_get_val(name, env)))
	{
		tmp = ft_strsub(param, 0, j);
		ft_strdel(&param);
		param = ft_str_j(tmp, val, 3);
	}
	else
	{
		free(param);
		param = ft_strnew(2);
	}
	ft_strdel(&name);
	return (param);
}

char		**sh_substitute_env_vars(char **params, t_lst *env)
{
	int i;
	int j;

	i = -1;
	while (params[++i])
	{
		j = -1;
		while (params[i][++j])
		{
			if (params[i][j] == '$' && params[i][j + 1])
				params[i] = substitute_env_vars(params[i], env, j);
		}
	}
	return (params);
}
