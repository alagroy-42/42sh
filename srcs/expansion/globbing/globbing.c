/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsaltel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:25:26 by vsaltel           #+#    #+#             */
/*   Updated: 2019/10/30 13:25:29 by vsaltel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "lexer.h"
#include "libft.h"

void		set_glob(t_globbing *glob, t_token *token)
{
	glob->nb_file = 0;
	glob->token = token;
	glob->root = (token->content[0] == '/');
	glob->list = create_globbing(pull_multi_occ(token->content, '*'));
}

int			replace_globbing(t_token *token, t_var *vars)
{
	t_token		*begin;
	t_token		*token_next;
	char		*tmp;
	t_globbing	glob;
	int			ret;

	begin = token;
	while (token)
	{
		ret = 0;
		token_next = token->next;
		if (is_word_token(token) && is_glob_str(token->content))
		{
			set_glob(&glob, token);
			ret = dir_globbing(&glob, glob.list, glob.root
				? ft_strdup("/") : ft_strdup("./"));
			token->is_glob_sub = glob.nb_file;
			free_globbing(glob.list);
		}
		token = token_next;
	}
	remove_token(begin);
	return (ret);
}
