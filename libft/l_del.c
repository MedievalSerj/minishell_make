/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:45:17 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/26 15:45:20 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sub_l_del(t_lst **head, void (*f)(void *content))
{
	t_lst	*next;
	t_lst	*tmp;

	tmp = *head;
	next = tmp->next;
	(*f)(tmp->content);
	free(tmp);
	*head = next;
	return ;
}

void		l_del(t_lst **head, t_lst *this, void (*f)(void *content))
{
	t_lst	*prev;
	t_lst	*next;
	t_lst	*tmp;

	if (!(this && head && (tmp = *head)))
		return ;
	if (tmp->content == this->content)
	{
		sub_l_del(head, f);
		return ;
	}
	prev = tmp;
	while (tmp)
	{
		if (tmp->content == this->content)
		{
			next = tmp->next;
			(*f)(tmp->content);
			free(tmp);
			prev->next = next;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
