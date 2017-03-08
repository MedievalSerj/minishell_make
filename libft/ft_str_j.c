/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:34:28 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/16 16:34:32 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sub_free(char **s1, char **s2, int fr)
{
	if (fr == 3)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
	else if (fr == 1)
		ft_strdel(s1);
	else if (fr == 2)
		ft_strdel(s2);
}

char		*ft_str_j(char *s1, char *s2, int fr)
{
	int		i;
	int		j;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		j++;
		i++;
	}
	s[i] = '\0';
	if (fr)
		sub_free(&s1, &s2, fr);
	return (s);
}
