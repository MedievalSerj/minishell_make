/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:51:37 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/18 16:51:50 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_builtin(char *s)
{
	if (ft_strequ(s, "echo") || ft_strequ(s, "cd") || ft_strequ(s, "setenv")
		|| ft_strequ(s, "unsetenv") || ft_strequ(s, "env")
		|| ft_strequ(s, "exit"))
		return (1);
	return (0);
}

static char		**substitute_home_dir(char **params, t_lst *env)
{
	int		i;
	char	*home;
	char	*tmp;

	i = -1;
	while (params[++i])
	{
		if (params[i][0] == '~' && (params[i][1] == '\0'
			|| params[i][1] == '/'))
		{
			home = sh_get_val("HOME", env);
			tmp = ft_strdup(params[i]);
			free(params[i]);
			params[i] = ft_str_j(home, ft_strsub(tmp, 1, ft_strlen(tmp)), 3);
			free(tmp);
		}
	}
	return (params);
}

static char		*substitute_tabs(char *arg)
{
	int i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == 9)
			arg[i] = ' ';
	}
	return (arg);
}

static t_cmd	*clear_params(char ***params)
{
	ft_clear_arr(params);
	return (NULL);
}

t_cmd			*sh_get_cmd(char *arg, t_lst *env)
{
	char	**params;
	t_cmd	*cmd;

	if (arg[0] == '\0')
		return (NULL);
	arg = substitute_tabs(arg);
	if (!(params = sh_parse_args(arg)) || !(*params))
		return (NULL);
	params = sh_substitute_env_vars(params, env);
	params = substitute_home_dir(params, env);
	if (params[0][0] == '\0')
		return (clear_params(&params));
	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->name = ft_strdup(params[0]);
	cmd->options_args = params;
	cmd->builtin = 0;
	cmd->path = NULL;
	if (!(cmd->builtin = is_builtin(cmd->name)))
		cmd->path = sh_get_exec_path(cmd->name, env);
	if (cmd->path == NULL && cmd->builtin == 0)
	{
		sh_del_cmd(&cmd);
		return (NULL);
	}
	return (cmd);
}
