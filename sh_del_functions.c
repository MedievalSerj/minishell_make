/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_del_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:03:47 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/27 13:03:48 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_env_entry(void *content)
{
	t_env *tmp;

	tmp = (t_env*)content;
	free(tmp->key);
	free(tmp->val);
	free(content);
}

void	sh_del_cmd(t_cmd **cmd)
{
	int i;

	if ((*cmd)->name)
		free((*cmd)->name);
	if ((*cmd)->path)
		free((*cmd)->path);
	if ((*cmd)->options_args)
	{
		i = -1;
		while ((*cmd)->options_args[++i])
			free((*cmd)->options_args[i]);
		free((*cmd)->options_args);
	}
	free(*cmd);
	*cmd = NULL;
}

void	sh_del_info(t_info **info)
{
	free((*info)->modes);
	free((*info)->path);
	free(*info);
	*info = NULL;
}
