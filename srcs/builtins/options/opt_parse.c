/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <pcharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:31:38 by frossiny          #+#    #+#             */
/*   Updated: 2020/01/31 15:49:22 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "opt.h"

static int			parse_mul(t_options *opts, char *opt, char *optstr, \
																char *bname)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (opt[++i])
	{
		if (ft_strchr(optstr, opt[i]))
		{
			tmp = ft_strsub(opt, i, 1);
			opt_add(opts, tmp, NULL);
			free(tmp);
		}
		else
		{
			write(2, bname, ft_strlen(bname));
			write(2, ": illegal option -- ", 20);
			write(2, opt + i, 1);
			write(2, "\n", 1);
			opts->ret = -1;
			return (0);
		}
	}
	return (1);
}

static int			parse_one(t_options *opts, t_cmd *cmd, int i, char *optstr)
{
	char	*find;

	if ((find = ft_strchr(optstr, cmd->args[i][1])))
	{
		if (find[1] == ':')
		{
			if (cmd->argc - i <= 1)
			{
				opts->ret = -2;
				return (-2);
			}
			opt_add(opts, cmd->args[i] + 1, cmd->args[i + 1]);
			i++;
			opts->last++;
		}
		opt_add(opts, cmd->args[i] + 1, NULL);
	}
	else
	{
		opts->ret = -1;
		return (-1);
	}
	return (i++);
}

static t_options	*init_struct(void)
{
	t_options	*options;

	if (!(options = (t_options *)malloc(sizeof(t_options))))
		return (NULL);
	options->opts = NULL;
	options->ret = 0;
	options->last = 1;
	return (options);
}

static t_options	*disp_errors(t_options *opts, int ret, char *bname, \
																char *arg)
{
	if (ret == -1)
		ft_dprintf(2, "42sh: %s: -%c: invalid option\n", bname, arg[1]);
	if (ret == -2)
		ft_dprintf(2, "42sh: %s: option requires an argument -- %c\n", bname,
		arg[1]);
	return (opts);
}

t_options			*opt_parse(t_cmd *cmd, char *optstring, char *bname)
{
	int			i;
	int			ret;
	t_options	*options;

	if (!(options = init_struct()))
		return (NULL);
	i = 0;
	while (++i < cmd->argc)
	{
		if (cmd->args[i][0] != '-' || ft_strlen(cmd->args[i]) < 2
			|| ft_strequ("--", cmd->args[i]))
			break ;
		if (ft_strlen(cmd->args[i]) > 2)
		{
			if (!parse_mul(options, cmd->args[i], optstring, bname))
				return (options);
		}
		else if ((ret = parse_one(options, cmd, i, optstring)) < 0)
			return (disp_errors(options, ret, bname, cmd->args[i]));
		options->last++;
	}
	return (options);
}
