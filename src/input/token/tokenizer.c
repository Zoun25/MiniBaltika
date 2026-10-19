/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaizoun <yzaizoun@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:41:16 by yzaizoun          #+#    #+#             */
/*   Updated: 2026/05/29 14:41:36 by yzaizoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <sys/types.h>
#include "linked_list.h"
#include "basic.h"
#include "token/token.h"

static bool	quote_checker(char *line)
{
	while (*line)
	{
		if (*line == '\'')
		{
			while (*line && *line != '\'')
				line++;
			if (!*line)
				return (false);
			line++;
		}
		else if (*line == '\"')
		{
			while (*line && *line != '\"')
				line++;
			if (!*line)
				return (false);
			line++;
		}
		else
			line++;
	}
	return (true);
}

char	*str_dup_from_to(char *line, int from, int to)
{
	char	*str;
	int		size;

	if (!line[from] || !line[to] || from > to)
		return (NULL);
	size = to - from;
	str = (char *)my_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	size = 0;
	while (from < to + 1)
	{
		str[size] = line[from];
		size++;
		from++;
	}
	str[size] = '\0';
	return (str);
}

bool	join_token_str(t_token_word *token, char *line, int *i, u_int8_t q_type)
{
	int	l;

	l = *i;
	while (line[l])
	{
		if (q_type == QUOTE_NONE && (line[l] == '\'' || line[l] == '\"'))
			break ;
		if (q_type == QUOTE_SINGLE && line[l] == '\'')
			break ;
		if (q_type == QUOTE_DOUBLE && line[l] == '\"')
			break ;
		l++;
	}
	token->str = str_dup_from_to(line, *i, l - 1);
	if (token->str == NULL)
		return (false);
	if (line[l + 1] == '\0' || line[l + 1] != ' ')
		token->concat = false;
	else
		token->concat = true;
	return (true);
}

bool	add_token_word(char *line, t_list *tokens, int *i, u_int8_t q_type)
{
	t_token_word	*token;

	if (q_type != QUOTE_NONE)
		*i += 1;
	token = (t_token_word *)my_calloc(1, sizeof(t_token_word));
	if (token == NULL)
		return (false);
	token->type.type = TOKEN_WORD;
	token->quote = q_type;
	if (join_token_str(token, line, i, q_type) == false)
		return (false);
	list_append(tokens, token);
	return (true);
}

static u_int8_t	token_class(char *line, int i)
{
	if (line[i] == ';')
		return (TOKEN_SEMICOLON);
	if (line[i] == '&' && line[i + 1] == '&')
		return (TOKEN_AND);
	if (line[i] == '|' && line[i + 1] == '|')
		return (TOKEN_OR);
	if (line[i] == '|')
		return (TOKEN_PIPE);
	if (line[i] == '<' || line[i] == '>')
		return (TOKEN_REDIRECTION);
	return (TOKEN_WORD);
}

bool	add_token_simple(t_list *tokens, int *i, u_int8_t class)
{
	t_token	*token;

	token = (t_token *)my_calloc(1, sizeof(t_token));
	if (token == NULL )
		return (false);
	token->type = class;
	list_append(tokens, token);
	if (class == TOKEN_OR || class == TOKEN_AND)
		*i += 2;
	else
		*i += 1;
	return (true);
}

static u_int8_t	redir_class(char *line, int i)
{
	if (line[i] == '<' && line[i + 1] == '<')
		return (DUAL_INPUT);
	if (line[i] == '>' && line[i + 1] == '>')
		return (DUAL_OUTPUT);
	if (line[i] == '<')
		return (SINGLE_INPUT);
	if (line[i] == '>')
		return (SINGLE_OUTPUT);
	return (NON);
}

bool	add_token_redir(char *line, t_list *tokens, int *i)
{
	t_token_redir	*token;

	if (redir_class(line, *i) == NON)
		return (false);
	token = (t_token_redir *)my_calloc(1, sizeof(t_token_redir));
	if (token == NULL)
		return (false);
	token->type.type = TOKEN_REDIRECTION;
	token->redirection = redir_class(line, *i);
	list_append(tokens, token);
	if (token->redirection == DUAL_INPUT || token->redirection == DUAL_OUTPUT)
		*i += 2;
	else
		*i += 1;
	return (true);
}

static bool	add_token(char *line, t_list *tokens, int *i)
{
	u_int8_t	class;

	while (line[*i] == ' ')
		*i += 1;
	class = token_class(line, *i);
	if (class == TOKEN_SEMICOLON || class == TOKEN_PIPE || class == TOKEN_OR
		|| class == TOKEN_AND)
		return (add_token_simple(tokens, i, class));
	if (class == TOKEN_REDIRECTION)
		return (add_token_redir(line, tokens, i));
	if (class == TOKEN_WORD)
		return (add_token_word(line, tokens, i, QUOTE_NONE));
	return (false);
}

bool	tokenize(char *line, t_list *tokens)
{
	int		i;

	if (!line || !quote_checker(line))
		return (false);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			if (!add_token_word(line, tokens, &i, QUOTE_SINGLE))
				return (false);
		}
		else if (line[i] == '\"')
		{
			if (!add_token_word(line, tokens, &i, QUOTE_DOUBLE))
				return (false);
		}
		else
		{
			if (!add_token(line, tokens, &i))
				return (false);
		}
	}
	return (true);
}
