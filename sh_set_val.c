/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_set_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:24:07 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/04 19:24:08 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_set_val(char *key, char *val, t_lst **env)
{
	t_env *current;
	t_lst *tmp;

	tmp = *env;
	while (tmp)
	{
		current = (t_env*)tmp->content;
		if (ft_strequ(current->key, key))
		{
			free(current->val);
			current->val = ft_strdup(val);
			return ;
		}
		tmp = tmp->next;
	}
	*env = l_add(*env, sh_new_entry(key, val));
}
