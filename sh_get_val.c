/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:12:32 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/18 19:12:34 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*sh_get_val(char *name, t_lst *env)
{
	t_env *tmp;

	while (env && name)
	{
		tmp = ((t_env*)(env->content));
		if (ft_strequ(tmp->key, name))
			return (ft_strdup(tmp->val));
		env = env->next;
	}
	return (NULL);
}
