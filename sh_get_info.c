/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:16:19 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 16:16:22 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		get_filetype(mode_t mode)
{
	char type;

	if ((mode & 0160000) == 0160000)
		type = 'w';
	else if ((mode & 0140000) == 0140000)
		type = 's';
	else if ((mode & 0120000) == 0120000)
		type = 'l';
	else if ((mode & 0100000) == 0100000)
		type = '-';
	else if ((mode & 0060000) == 0060000)
		type = 'b';
	else if ((mode & 0040000) == 0040000)
		type = 'd';
	else if ((mode & 0020000) == 0020000)
		type = 'c';
	else if ((mode & 0010000) == 0010000)
		type = 'p';
	else
		type = 'x';
	return (type);
}

char		*get_modes(mode_t mode)
{
	char	*modes;
	int		n;

	n = mode & 07777;
	modes = ft_strnew(11);
	modes[0] = get_filetype(mode);
	modes[1] = (n & 0400) == 0400 ? (char)'r' : (char)'-';
	modes[2] = (n & 0200) == 0200 ? (char)'w' : (char)'-';
	if ((n & 0100) == 0100)
		modes[3] = (n & 04000) == 04000 ? (char)'s' : (char)'x';
	else
		modes[3] = (n & 04000) == 04000 ? (char)'S' : (char)'-';
	modes[4] = (n & 040) == 040 ? (char)'r' : (char)'-';
	modes[5] = (n & 020) == 020 ? (char)'w' : (char)'-';
	if ((n & 010) == 010)
		modes[6] = (n & 02000) == 02000 ? (char)'s' : (char)'x';
	else
		modes[6] = (n & 02000) == 02000 ? (char)'S' : (char)'-';
	modes[7] = (n & 04) == 04 ? (char)'r' : (char)'-';
	modes[8] = (n & 02) == 02 ? (char)'w' : (char)'-';
	if ((n & 01000) == 01000)
		modes[9] = 't';
	else
		modes[9] = (n & 01) == 01 ? (char)'x' : (char)'-';
	return (modes);
}

t_info		*get_info(char *path)
{
	t_info		*info;
	struct stat	*buf;

	info = (t_info*)malloc(sizeof(t_info));
	buf = (struct stat*)malloc(sizeof(struct stat));
	if (stat(path, buf) == -1)
	{
		free(info);
		free(buf);
		return (NULL);
	}
	info->path = ft_strdup(path);
	info->type = get_filetype(buf->st_mode);
	info->modes = get_modes(buf->st_mode);
	free(buf);
	return (info);
}
