/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:18:50 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/05 16:18:52 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_arr(t_lst *head)
{
	t_lst	*tmp;
	int		i;
	int		n;
	char	**ret;

	if (!head)
		return (NULL);
	tmp = head;
	n = l_count(tmp);
	ret = (char**)malloc(sizeof(char*) * (n + 1));
	i = 0;
	while (tmp)
	{
		ret[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
