/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:40:21 by frossiny          #+#    #+#             */
/*   Updated: 2019/11/09 16:47:56 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "structs.h"

t_builtin	get_builtin(char *name);
int			is_builtin(char *name);

/*
** Builtins functions
*/
int			handle_builtin(t_cmd *cmd, t_shell *shell);
int			b_set(t_cmd *cmd, t_shell *shell);
int			b_unset(t_cmd *cmd, t_shell *shell);
int			b_exit(t_cmd *cmd, t_shell *shell);
int			b_cd(t_cmd *cmd, t_shell *shell);
int			b_echo(t_cmd *cmd, t_shell *shell);
int			b_export(t_cmd *cmd, t_shell *shell);
int			b_history(t_cmd *cmd, t_shell *shell);
int			b_type(t_cmd *cmd, t_shell *shell);
int			b_alias(t_cmd *cmd, t_shell *shell);
int			b_unalias(t_cmd *cmd, t_shell *shell);

/*
** Cd internal functions
*/
char		*cd_buildpath(char *path);

/*
** history internal functions
*/
void		parse_and_add_hist(t_cmd *cmd, t_shell *shell);
void		empty_hist(t_shell *shell);

static const t_builtin g_builtins[] =
{
	{ "echo", &b_echo },
	{ "cd", &b_cd },
	{ "set", &b_set },
	{ "unset", &b_unset },
	{ "exit", &b_exit },
	{ "export", &b_export },
	{ "type", &b_type },
	{ "alias", &b_alias },
	{ "unalias", &b_unalias },
	{ "history", &b_history},
	{ NULL, NULL }
};

#endif
