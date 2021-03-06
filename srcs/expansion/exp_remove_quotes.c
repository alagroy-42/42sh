/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_remove_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:47:37 by frossiny          #+#    #+#             */
/*   Updated: 2020/01/13 14:45:55 by vsaltel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "expansion.h"
#include "lexer.h"
#include "utils.h"

static int	is_opening_quote(t_expansion *e)
{
	if (e->str[e->i] == '\'' && e->isquote == 0)
		return (1);
	if (e->str[e->i] == '"' && e->isquote == 0)
		return (1);
	return (0);
}

static int	is_closing_quote(t_expansion *e)
{
	if (e->str[e->i] == '\'' && e->isquote == 1)
		return (1);
	if (e->str[e->i] == '"' && e->isquote == 2)
		return (1);
	return (0);
}

static int	remove_quotes(t_expansion *e)
{
	while (e->str[++(e->i)])
	{
		if (is_opening_quote(e))
		{
			if (is_escaped(e->str, e->i, 0))
				continue ;
			exp_join(e, ft_strsub(e->str, e->li, e->i - e->li), 0);
			e->li = e->i + 1;
			e->isquote = e->str[e->i] == '"' ? 2 : 1;
		}
		else if (is_closing_quote(e))
		{
			if (is_escaped(e->str, e->i, 0) && e->isquote != 1)
				continue ;
			exp_join(e, ft_strsub(e->str, e->li, e->i - e->li), 0);
			e->li = e->i + 1;
			e->isquote = 0;
		}
	}
	if (e->i > e->li)
		exp_join(e, ft_strsub(e->str, e->li, e->i - e->li), 0);
	return (1);
}

int			exp_remove_quotes(t_token *token)
{
	t_expansion	exp;

	exp_set_struct(&exp, token->content);
	if (!remove_quotes(&exp))
		return (0);
	if (exp.new)
		tok_replace(token, exp.new);
	return (1);
}
