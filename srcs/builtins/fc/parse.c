/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <pcharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 01:34:27 by pcharrie          #+#    #+#             */
/*   Updated: 2019/11/12 02:13:48 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "utils.h"
#include "shell.h"
#include "libft.h"
#include "variables.h"
#include "builtins.h"
#include "opt.h"

int		fc_parse_options(t_cmd *cmd, t_fc_vars *fc)
{
	int i;
	int j;

	i = 0;
	while (++i < cmd->argc)
	{
		if (ft_strlen(cmd->args[i]) > 1 && cmd->args[i][0] == '-' && !ft_isnumeric(cmd->args[i]))
		{
			j = 0;
			while (cmd->args[i][++j])
			{
				if (cmd->args[i][j] == 'e')
				{
					if (j < ft_strlen(cmd->args[i]) - 1)
					{
						if (!(fc->editor = ft_strnew(ft_strlen(cmd->args[i]) - j + 1)))
							return (0);
						ft_strcpy(fc->editor, cmd->args[i] + j + 1);
					}
					else if (cmd->args[i + 1])
					{
						if (!(fc->editor = ft_strdup(cmd->args[i + 1])))
							return (0);
					}
					else
					{
						ft_putendl_fd("42sh: fc: -e: option requires an argument", 2);
						return (-1);
					}
					break;
				}
				else if (cmd->args[i][j] == 'l' || cmd->args[i][j] == 's')
					cmd->args[i][j] == 'l' ? (fc->list = 1) : (fc->exec = 1);
				else if (cmd->args[i][j] == 'n' || cmd->args[i][j] == 'r')
					cmd->args[i][j] == 'n' ? (fc->rm = 1) : (fc->rv = 1);
				else
				{
					ft_dprintf(2, "42sh: fc: -%c: invalid option\n", cmd->args[i][j]);
					return (-1);
				}
			}
		}
		else
			break ;
	}
	fc->i = i;
	return (1);
}

int		fc_histo_lst_size(void)
{
	t_histo_lst	*lst;
	int			i;

	lst = g_shell.history.lst;
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	fc_fix_range(t_fc_vars *fc)
{
	int hist_size;

	hist_size = fc_histo_lst_size();
	if (fc->from < 0)
	{
		fc->from = (hist_size - 15 < 0 ? 0 : hist_size - 15);
		fc->to = hist_size;
	}
	if (fc->to > -1 && fc->to < fc->from)
	{
		hist_size = fc->to;
		fc->to = fc->from;
		fc->from = hist_size;
		fc->rv = 1;
	}
}

int		fc_parse_range(t_cmd *cmd, t_fc_vars *fc)
{
	if (cmd->args[fc->i])
	{
		if (!ft_isnumeric(cmd->args[fc->i]))
			return (0);
		fc->from = ft_atoi(cmd->args[fc->i++]);
	}
	if (cmd->args[fc->i])
	{
		if (!ft_isnumeric(cmd->args[fc->i]))
			return (0);
		fc->to = ft_atoi(cmd->args[fc->i++]);
	}
	fc_fix_range(fc);
	return (1);
}
