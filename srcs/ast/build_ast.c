/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:17:59 by frossiny          #+#    #+#             */
/*   Updated: 2019/11/08 16:09:49 by frossiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "reader.h"

static int	parse_tree(t_token *tokens, t_anode **ast)
{
	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE || tokens->type == TOKEN_AND
											|| tokens->type == TOKEN_OR)
		{
			if (!*ast)
				return (0);
			tokens = create_ope_node(ast, tokens);
		}
		else if (tok_is_word(tokens) || tokens->type == TOKEN_ASSIGNMENT)
			tokens = create_cmd_node(ast, tokens);
		else if (tokens->type == TOKEN_SEMI)
			tokens = tokens->next;
		else
			break ;
	}
	return (1);
}

int			build_ast(t_shell *shell)
{
	return (parse_tree(shell->lexer.tokens, &(shell->ast)));
}
