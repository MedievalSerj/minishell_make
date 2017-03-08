/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:01:32 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/28 17:01:33 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	l_add_last(t_lst **head, void *content)
{
	t_lst *tmp;
	t_lst *new;

	if (!(tmp = *head))
	{
		new = (t_lst*)malloc(sizeof(t_lst));
		new->content = content;
		new->next = NULL;
		*head = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	new = (t_lst*)malloc(sizeof(t_lst));
	new->content = content;
	new->next = NULL;
	tmp->next = new;
}
