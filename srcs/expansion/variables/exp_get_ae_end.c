/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_get_ae_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:08:53 by frossiny          #+#    #+#             */
/*   Updated: 2020/02/03 19:26:39 by frossiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

size_t	exp_get_ae_end(char *src)
{
	size_t	i;
	size_t	count;

	if (!src)
		return (1);
	if (!ft_strnequ(src, "$((", 3))
		return (1);
	i = 2;
	count = 1;
	while (src[++i] && count)
	{
		if (ft_strnequ(src + i, "$((", 3))
			count++;
		if (ft_strnequ(src + i, "))", 2))
			count--;
	}
	return (i);
}
