/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:19:59 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/28 15:20:00 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sh_sub_setenv(t_cmd *cmd, t_lst **env)
{
	t_env *tmp;

	tmp = (t_env*)malloc(sizeof(t_env));
	tmp->key = ft_strdup(cmd->options_args[1]);
	tmp->val = (cmd->options_args[2] != NULL ? ft_strdup(cmd->options_args[2]) \
		: ft_strnew(2));
	l_add_last(env, tmp);
}

static void	sh_sub_setenv2(t_env *pmt, t_cmd *cmd)
{
	free(pmt->key);
	free(pmt->val);
	pmt->key = ft_strdup(cmd->options_args[1]);
	pmt->val = (cmd->options_args[2] != NULL ? ft_strdup(cmd->options_args[2]) \
		: ft_strnew(2));
}

void		sh_setenv(t_cmd *cmd, t_lst **env)
{
	t_lst *tmp;
	t_env *pmt;

	if (cmd->options_args[1] == NULL)
		sh_env(cmd, env);
	else if (cmd->options_args[1] && cmd->options_args[2] &&
		cmd->options_args[3])
		ft_putendl("setenv: Too many arguments.");
	else
	{
		tmp = *env;
		while (tmp)
		{
			pmt = (t_env*)(tmp->content);
			if (ft_strequ(pmt->key, cmd->options_args[1]))
			{
				sh_sub_setenv2(pmt, cmd);
				return ;
			}
			tmp = tmp->next;
		}
		sh_sub_setenv(cmd, env);
	}
}
