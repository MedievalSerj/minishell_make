/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:11:43 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/18 16:11:46 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_readline(int fd, char **line)
{
	char	*buf;
	int		n;
	int		l;
	int		total;

	n = BUFF_SIZE;
	buf = ft_strnew((size_t)n);
	total = 0;
	while ((l = (int)read(fd, buf + total, 1)) > 0)
	{
		if (buf[total] == '\n')
			break ;
		total += l;
		if (total >= (n - 2))
			buf = resize_buf(buf, &n);
	}
	if (l == -1)
		return (-1);
	buf[total] = '\0';
	*line = buf;
	return (l);
}
