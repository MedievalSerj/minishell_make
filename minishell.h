/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:24:42 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/15 16:24:46 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H
# define __MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>

enum			e_f_num
{
	ECHO = 0,
	CD,
	SETENV,
	UNSETENV,
	ENV,
	EXIT,
	LENGTH
};
typedef struct	s_env
{
	char		*key;
	char		*val;
}				t_env;
typedef struct	s_info
{
	char		*path;
	char		type;
	char		*modes;
}				t_info;
typedef struct	s_cmd
{
	char		*name;
	char		*path;
	char		**options_args;
	int			builtin;
}				t_cmd;
typedef void	(*t_funct)(t_cmd *cmd, t_lst **env);
void			sh_exit(t_cmd *cmd, t_lst **env);
void			sh_unsetenv(t_cmd *cmd, t_lst **env);
void			sh_env(t_cmd *cmd, t_lst **env);
void			sh_setenv(t_cmd *cmd, t_lst **env);
void			sh_echo(t_cmd *cmd, t_lst **env);
void			sh_cd(t_cmd *cmd, t_lst **env);
char			get_filetype(mode_t mode);
char			*get_modes(mode_t mode);
t_info			*get_info(char *path);
char			**sh_parse_args(char *s);
t_lst			*sh_cp_environ(char **envp);
void			del_env_entry(void *content);
char			**sh_get_ch_env(t_lst *env);
t_cmd			*sh_get_cmd(char *arg, t_lst *env);
void			sh_del_cmd(t_cmd **cmd);
char			*sh_get_val(char *name, t_lst *env);
char			*sh_get_exec_path(char *name, t_lst *env);
void			sh_del_info(t_info **info);
void			sh_exec_builtin(t_cmd *cmd, t_lst **env);
t_env			*sh_new_entry(char *key, char *val);
void			sh_set_val(char *key, char *val, t_lst **env);
char			*sh_get_root_path(char *name, char *pwd);
void			sh_perror(char *s1, char *s2, char *s3);
char			**sh_substitute_env_vars(char **params, t_lst *env);
#endif
