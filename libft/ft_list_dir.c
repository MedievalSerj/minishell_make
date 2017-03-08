/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:05:33 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/19 15:05:35 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_dir(char *path)
{
	DIR				*dir;
	struct dirent	*entry;
	t_list			*head;
	t_list			*tmp;

	if ((dir = opendir(path)) == NULL)
		return (NULL);
	head = NULL;
	while ((entry = readdir(dir)) != NULL)
	{
		tmp = ft_lstnew(entry->d_name, (ft_strlen(entry->d_name) + 1));
		ft_lstadd(&head, tmp);
	}
	closedir(dir);
	return (head);
}
