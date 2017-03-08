/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cp_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:28:20 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/18 16:28:23 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_chr_key(char *s)
{
	char	*key;
	int		i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	key = ft_strnew((size_t)i + 1);
	key = ft_strncpy(key, s, (size_t)i);
	return (key);
}

t_lst		*sh_cp_environ(char **envp)
{
	t_lst	*env;
	t_env	*entry;
	int		i;

	env = NULL;
	i = -1;
	while (envp[++i])
	{
		entry = (t_env*)malloc(sizeof(t_env));
		entry->key = get_chr_key(envp[i]);
		entry->val = ft_strdup((ft_strchr(envp[i], '=') + 1));
		env = l_add(env, entry);
	}
	return (env);
}
