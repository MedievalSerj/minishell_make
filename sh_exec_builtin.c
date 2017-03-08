/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:05:55 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/22 13:05:56 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**init_builtin_names(void)
{
	char **tmp;

	tmp = (char**)malloc(sizeof(char*) * LENGTH + 1);
	tmp[ECHO] = ft_strdup("echo");
	tmp[CD] = ft_strdup("cd");
	tmp[SETENV] = ft_strdup("setenv");
	tmp[UNSETENV] = ft_strdup("unsetenv");
	tmp[ENV] = ft_strdup("env");
	tmp[EXIT] = ft_strdup("exit");
	tmp[LENGTH] = NULL;
	return (tmp);
}

static t_funct	*create_funct_arr(void)
{
	t_funct *funct_arr;

	funct_arr = (t_funct*)malloc(sizeof(t_funct) * LENGTH);
	funct_arr[ECHO] = sh_echo;
	funct_arr[CD] = sh_cd;
	funct_arr[SETENV] = sh_setenv;
	funct_arr[UNSETENV] = sh_unsetenv;
	funct_arr[ENV] = sh_env;
	funct_arr[EXIT] = sh_exit;
	return (funct_arr);
}

static t_funct	*dispatch(t_funct *f, char **b_names, t_cmd *cmd)
{
	int i;

	i = -1;
	while (++i < LENGTH)
	{
		if (ft_strequ(b_names[i], cmd->name))
			return (&f[i]);
	}
	return (NULL);
}

void			sh_exec_builtin(t_cmd *cmd, t_lst **env)
{
	t_funct	*funct_arr;
	char	**builtin_names;
	t_funct	*funct;

	funct_arr = create_funct_arr();
	builtin_names = init_builtin_names();
	funct = dispatch(funct_arr, builtin_names, cmd);
	(*funct)(cmd, env);
	ft_clear_arr(&builtin_names);
	free(funct_arr);
}
