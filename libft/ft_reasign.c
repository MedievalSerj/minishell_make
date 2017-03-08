/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reasign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:46:22 by sladonia          #+#    #+#             */
/*   Updated: 2017/03/04 17:46:24 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reasign(char *this, char *new, int free_new)
{
	char *tmp;

	tmp = ft_strdup(new);
	free(this);
	if (free_new)
		free(new);
	return (tmp);
}
