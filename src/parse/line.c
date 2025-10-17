/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:30:07 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 04:27:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#include "basic.h"
#include "node/create.h"

static t_node	*make_chunk(enum e_node_type type, t_node *a, t_node *b)
{
	t_node	*result;

	if (type == AND)
		result = node_create_and(a, b);
	else if (type == OR)
		result = node_create_or(a, b);
	else if (type == SEMICOLON)
		result = node_create_semicolon(a, b);
	else
		result = NULL;
	if (result == NULL || a == NULL || b == NULL)
	{
		node_destroy(result);
		node_destroy(a);
		node_destroy(b);
		return (NULL);
	}
	return (result);
}

void	avoid_quotes(char *line, int *i, size_t begin, size_t end)
{
	int		i_copy;
	char	quote;

	if (line[begin + *i] != '\'' && line[begin + *i] != '"')
		return ;
	quote = line[begin + *i];
	i_copy = *i;
	*i += 1;
	while (begin + *i < end)
	{
		if (line[begin + *i] == quote)
		{
			*i += 1;
			return ;
		}
		*i += 1;
	}
	*i = i_copy;
}

static t_node	*parse_chunks(t_shinf *sh, char *line, size_t begin, size_t end)
{
	static char				*separators[] = {"&&", "||", NULL};
	static enum e_node_type	types[] = {AND, OR, SEMICOLON};
	int						i;
	int						sep;

	i = 0;
	while (begin + i < end)
	{
		avoid_quotes(line, &i, begin, end);
		sep = 0;
		while (separators[sep])
		{
			if (begin + i + my_strlen(separators[sep]) < end)
				if (my_memcmp(&line[begin + i], separators[sep],
						my_strlen(separators[sep])) == 0)
					return (make_chunk(types[sep],
							parse_chunks(sh, line, begin, begin + i),
							parse_chunks(sh, line,
								begin + i + my_strlen(separators[sep]), end)));
			sep ++;
		}
		i ++;
	}
	return (parse_block(sh, line, begin, end));
}

t_node	*parse_line(t_shinf *sh, char *line)
{
	size_t	len;
	t_node	*node;
	t_node	*child;

	len = my_strlen(line);
	if (len == 0)
		return (node_create_nop());
	child = parse_chunks(sh, line, 0, len - (line[len - 1] == '\n'));
	if (child == NULL)
		return (NULL);
	node = node_create_line(child);
	if (node == NULL)
		node_destroy(child);
	return (node);
}
