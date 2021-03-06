/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:47:31 by alagroy-          #+#    #+#             */
/*   Updated: 2020/01/07 19:03:08 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H
# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"
# include "lexer.h"
# include "shell.h"
# include "structs.h"
# include "termcaps.h"
# define CMD 1
# define FILE 2
# define VAR 3

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

int						lite_parser(t_cursor_pos *pos, int i);
t_list					*compl_file(char *compl, t_shell *shell, int *len);
t_list					*compl_cmd(char *compl, t_shell *shell, int *len);
t_list					*compl_var(char *compl, t_shell *shell, int *len);
t_list					*find_file(char *path, char *file);
void					disp_compl(t_cursor_pos *pos, char **str, t_list *list,
						int len);
t_list					*compl_alias_builtins(t_list *compl_lst, char *compl,
						t_shell *shell);

#endif
