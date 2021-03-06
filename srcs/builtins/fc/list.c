/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <pcharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 01:29:44 by pcharrie          #+#    #+#             */
/*   Updated: 2020/02/19 15:39:03 by vsaltel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"

static void	fc_list_print_str(char *str, int n, int rm)
{
	if (!rm)
		ft_printf("%d", n);
	ft_printf("	%s\n", str);
}

static void	fc_list_print(t_fc_vars *fc)
{
	int i;
	int j;

	i = fc->tab_len - 1;
	j = fc->from;
	while (i >= 0)
		fc_list_print_str(fc->tab[i--], j++, fc->rm);
}

static void	fc_list_print_reverse(t_fc_vars *fc)
{
	int i;
	int j;

	i = 0;
	j = fc->from + fc->tab_len - 1;
	while (fc->tab[i])
		fc_list_print_str(fc->tab[i++], j--, fc->rm);
}

void		fc_list(t_fc_vars *fc)
{
	(fc->rv ? fc_list_print_reverse(fc) : fc_list_print(fc));
}
