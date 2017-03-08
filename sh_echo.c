/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:21:21 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/28 15:21:23 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		echo_n_option(char **args, int *i)
{
	int j;
	int n;

	n = 0;
	while (args[++(*i)] && args[(*i)][0] == '-')
	{
		j = 0;
		if (ft_strequ(args[(*i)], "-"))
			return (n);
		while (args[(*i)][++j])
		{
			if (args[(*i)][j] == 'n')
				n = 1;
			else
			{
				if ((*i) == 1)
					n = 0;
				(*i)--;
				return (n);
			}
		}
	}
	(*i)--;
	return (n);
}

void	sh_echo(t_cmd *cmd, t_lst **env)
{
	int i;
	int f;
	int n_option;

	(void)env;
	i = 0;
	f = 0;
	n_option = echo_n_option(cmd->options_args, &i);
	while (cmd->options_args[++i])
	{
		if (f)
			write(1, " ", 1);
		ft_putstr(cmd->options_args[i]);
		f = 1;
	}
	if (n_option && (ft_strnequ(cmd->options_args[i - 1], "-n", 2) || \
		cmd->options_args[i - 1][0] == '\0'))
		return ;
	else if (n_option)
		ft_putchar('%');
	ft_putendl("");
}
