/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:27 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/24 16:27:29 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dequout(char **s, int *i, t_lst **head)
{
	int k;
	int n;

	k = (*i);
	n = 0;
	while ((*s)[++k])
	{
		if ((*s)[k] == '\"' && n == 0)
		{
			l_add_last(head, ft_strnew(1));
			(*i) = k;
			return ;
		}
		else if ((*s)[k] == '\"')
		{
			l_add_last(head, ft_strsub(*s, (*i) + 1, n));
			(*i) = k;
			return ;
		}
		n++;
	}
}

static void	get_word(char **s, int *i, t_lst **head)
{
	int k;
	int n;

	k = (*i) - 1;
	n = 0;
	while ((*s)[++k])
	{
		if ((*s)[k] == ' ')
		{
			l_add_last(head, ft_strsub(*s, (*i), n));
			(*i) = k - 1;
			return ;
		}
		n++;
	}
	l_add_last(head, ft_strsub(*s, (*i), n));
	(*i) = k - 1;
}

char		**sh_parse_args(char *s)
{
	int		i;
	t_lst	*head;
	char	**ret;

	if (!s)
		return (NULL);
	i = -1;
	head = NULL;
	while (s[++i])
	{
		if (s[i] == '\"')
			dequout(&s, &i, &head);
		else if (s[i] == ' ')
			continue ;
		else
			get_word(&s, &i, &head);
	}
	ret = ft_lst_to_arr(head);
	l_del_all(&head, free);
	return (ret);
}
