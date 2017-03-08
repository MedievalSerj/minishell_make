/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:18:11 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/28 15:18:12 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_env(t_cmd *cmd, t_lst **env)
{
	t_env	*entry;
	t_lst	*tmp;

	(void)cmd;
	tmp = *env;
	while (tmp)
	{
		entry = (t_env*)((tmp)->content);
		ft_putstr(entry->key);
		ft_putchar('=');
		ft_putendl(entry->val);
		(tmp) = (tmp)->next;
	}
}
