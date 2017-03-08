/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_count.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:35:18 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/26 18:35:19 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	l_count(t_lst *head)
{
	int n;

	n = 0;
	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}