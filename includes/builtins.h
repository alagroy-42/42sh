/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <pcharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:40:21 by frossiny          #+#    #+#             */
/*   Updated: 2019/11/06 17:31:34 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "structs.h"

int			handle_builtin(t_cmd *cmd, t_shell *shell);
t_builtin	get_builtin(char *name);
int			is_builtin(char *name);
char		*cd_buildpath(char *path);
int			cd_getpath(t_cmd *cmd, t_options *opts);
char		*cd_cdpath(t_var *cdpath, char *path);
int			cd_pathcheck(char *path, char *arg);
int			test_unary(t_cmd *cmd);
int			test_binary(t_cmd *cmd);
int			b_set(t_cmd *cmd, t_shell *shell);
int			b_unset(t_cmd *cmd, t_shell *shell);
int			b_exit(t_cmd *cmd, t_shell *shell);
int			b_cd(t_cmd *cmd, t_shell *shell);
int			b_echo(t_cmd *cmd, t_shell *shell);
int			b_export(t_cmd *cmd, t_shell *shell);
int			b_test(t_cmd *cmd, t_shell *shell);
int			b_fc(t_cmd *cmd, t_shell *shell);

#endif
