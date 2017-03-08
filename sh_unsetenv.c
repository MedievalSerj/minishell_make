/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:15:58 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/06 16:42:18 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_unsetenv(t_cmd *cmd, t_lst **env)
{
	t_lst	*tmp;
	t_lst	*next;
	t_env	*pmt;
	int		i;

	if (!(cmd->options_args[1]))
		sh_perror("unsetenv: Too few arguments.", NULL, NULL);
	next = *env;
	while (next)
	{
		tmp = next;
		next = next->next;
		pmt = (t_env*)(tmp->content);
		i = 0;
		while (tmp && cmd->options_args[++i])
		{
			if (ft_strequ(pmt->key, cmd->options_args[i]))
			{
				l_del(env, tmp, del_env_entry);
				tmp = NULL;
			}
		}
	}
}
