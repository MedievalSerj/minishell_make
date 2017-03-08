/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_new_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:53:52 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/02 14:53:53 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*sh_new_entry(char *key, char *val)
{
	t_env *tmp;

	tmp = (t_env*)malloc(sizeof(t_env));
	tmp->key = ft_strdup(key);
	tmp->val = ft_strdup(val);
	return (tmp);
}
