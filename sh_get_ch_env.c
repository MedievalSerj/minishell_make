/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_ch_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:40:09 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/05 12:40:10 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**sh_get_ch_env(t_lst *env)
{
	char	**tmp;
	int		n;
	int		i;
	t_env	*entry;

	n = l_count(env);
	if (!(tmp = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	i = 0;
	while (env)
	{
		entry = (t_env*)(env->content);
		tmp[i] = ft_str_j(entry->key, "=", 0);
		tmp[i] = ft_str_j(tmp[i], entry->val, 1);
		env = env->next;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
