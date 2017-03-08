/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:45:38 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/26 15:45:42 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	l_del_all(t_lst **head, void (*f)(void *content))
{
	t_lst *tmp;
	t_lst *to_del;

	if (!head)
		return ;
	tmp = *head;
	while (tmp)
	{
		(*f)(tmp->content);
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	*head = NULL;
}
