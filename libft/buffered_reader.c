/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:53:37 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/04 13:53:42 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*resize_buf(char *buf, int *n)
{
	char *tmp;

	tmp = ft_strdup(buf);
	ft_strdel(&buf);
	*n = (*n) * 2;
	buf = ft_strnew((size_t)(*n));
	buf = ft_strcpy(buf, tmp);
	ft_strdel(&tmp);
	return (buf);
}

char	*buffered_reader(int fd)
{
	long	len;
	long	total;
	char	*buf;
	int		n;

	n = BUFF_SIZE;
	total = 0;
	buf = ft_strnew((size_t)n);
	while ((len = read(fd, buf + total, 1)) > 0)
	{
		total += len;
		if (total >= (long)(n - 2))
			buf = resize_buf(buf, &n);
	}
	if (len == -1)
		return (NULL);
	buf[total] = '\0';
	return (buf);
}
