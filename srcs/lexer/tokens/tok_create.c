/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:03:37 by frossiny          #+#    #+#             */
/*   Updated: 2019/11/26 10:44:39 by frossiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"

t_token	*tok_create(t_lexer *lexer, char *content,
												size_t len, t_token_type type)
{
	t_token *token;

	if (!lexer || !(token = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	if (!(token->content = ft_strndup(content, len)))
	{
		free(token);
		return (NULL);
	}
	token->len = len;
	token->type = type;
	token->next = NULL;
	if (lexer->tokens)
		tok_push(lexer->tokens, token);
	else
		lexer->tokens = token;
	(lexer->size)++;
	lexer->last_token = token;
	return (token);
}
