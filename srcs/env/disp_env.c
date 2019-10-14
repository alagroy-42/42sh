/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:49:51 by frossiny          #+#    #+#             */
/*   Updated: 2019/10/14 18:45:33 by frossiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "shell.h"

int		disp_env(t_var *vars)
{
	if (!vars)
		return (0);
	while (vars)
	{
		ft_printf("%s=%s\n", vars->key, vars->value);
		vars = vars->next;
	}
	return (0);
}
