/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:04:49 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/12 21:37:20 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "linked_list.h"

# include <stdbool.h>

enum e_token_type
{
	TOKEN_SEMICOLON,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_PIPE,
	TOKEN_LINEBREAK,
	TOKEN_REDIRECTION,
	TOKEN_WORD,
};

typedef struct token
{
	enum e_token_type	type;
}	t_token;

enum e_quote_type
{
	QUOTE_NONE,
	QUOTE_SINGLE,
	QUOTE_DOUBLE,
};

typedef struct token_word
{
	t_token				type;
	char				*str;
	enum e_quote_type	quote;
	bool				concat;
}	t_token_word;

typedef enum redirections
{
	NON = 0b000,
	SINGLE_INPUT = 0b100,
	DUAL_INPUT = 0b110,
	SINGLE_OUTPUT = 0b101,
	DUAL_OUTPUT = 0b111,
	OUTPUT = 0b001,
	DUAL = 0b010,
	VALID = 0b100,
}	t_redir;

typedef struct token_redirection
{
	t_token	type;
	t_redir	redirection;
}	t_token_redir;

bool	tokenize(char *line, t_list *tokens);
void	token_destroy(t_token *token);

#endif
