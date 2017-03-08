/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:44:54 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/26 15:44:57 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*l_add(t_lst *head, void *content)
{
	t_lst *new;

	if (!content)
		return (head);
	new = (t_lst*)malloc(sizeof(t_lst));
	new->content = content;
	if (!head)
	{
		new->next = NULL;
		return (new);
	}
	new->next = head;
	return (new);
}
