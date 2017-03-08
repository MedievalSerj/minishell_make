/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_nth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:46:29 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/26 15:46:31 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	l_del_nth(t_lst **head, int n, void (*f)(void *content))
{
	t_lst *prev;
	t_lst *next;
	t_lst *tmp;

	if (!head)
		return ;
	if (n == 0 && *head)
	{
		tmp = *head;
		next = l_get_nth(*head, 1);
		(*f)(tmp->content);
		free(tmp);
		*head = next;
		return ;
	}
	else if ((tmp = l_get_nth(*head, n)))
	{
		prev = l_get_nth(*head, n - 1);
		next = l_get_nth(*head, n + 1);
		(*f)(tmp->content);
		free(tmp);
		prev->next = next;
		*head = prev;
	}
}
