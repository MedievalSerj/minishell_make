/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:51:39 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/18 13:51:41 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	base_case(t_lst **env, char *arg, t_cmd *cmd)
{
	pid_t child_pid;

	if (arg[0] != '\0')
		cmd = sh_get_cmd(arg, *env);
	if (cmd && cmd->builtin)
		sh_exec_builtin(cmd, env);
	else if (cmd)
	{
		child_pid = fork();
		if (child_pid == 0)
			execve(cmd->path, cmd->options_args, sh_get_ch_env(*env));
		else
			wait(&child_pid);
	}
	if (cmd)
		sh_del_cmd(&cmd);
	ft_strdel(&arg);
}

static void	loop(t_lst *env)
{
	char	*arg;
	int		prompt;
	t_cmd	*cmd;

	cmd = NULL;
	prompt = 1;
	while (1)
	{
		if (prompt >= 0)
			ft_putstr("$> ");
		prompt = ft_readline(0, &arg);
		if (prompt == 1)
			base_case(&env, arg, cmd);
	}
}

int			main(int ac, char **av, char **envp)
{
	t_lst *env;

	(void)ac;
	(void)av;
	env = sh_cp_environ(envp);
	loop(env);
}
