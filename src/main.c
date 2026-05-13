/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:55:22 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/13 21:33:01 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "input.h"
#include "node.h"
#include "env.h"
#include "token/token.h"

#include "basic.h"
#include "my_printf.h"
#include <stdio.h>

void	end(t_shinf *sh)
{
	int	status;

	status = sh->status_code;
	shinf_destroy(sh);
	exit(status);
}

t_node	*full_parse(t_shinf *sh, char *line)
{
	t_list	tokens;
	t_token	**array_tokens;
	t_node	*tree;

	list_initialize(&tokens, (void (*)(void *)) & token_destroy);
	if (!tokenize(line, &tokens))
		return (list_delete(&tokens), NULL);
	array_tokens = (t_token **)list_export(&tokens, NULL);
	if (array_tokens == NULL)
		return (list_delete(&tokens), NULL);
	tree = node_parse(sh, array_tokens, tokens.len);
	free(array_tokens);
	list_delete(&tokens);
	return (tree);
}

static void	loop(t_shinf *sh)
{
	char	*line;
	t_node	*tree;

	while (true)
	{
		line = mini_line(sh, true);
		if (line == NULL)
			break ;
		tree = full_parse(sh, line);
		if (!node_validate(tree))
		{
			sh->status_code = 1;
			free(line);
			continue ;
		}
		node_print(tree);
		sh->status_code = node_exec(sh, tree);
		node_destroy(tree);
		free(line);
	}
	end(sh);
}

int	main(int __attribute__((unused))argc, char __attribute__((unused))**argv,
	char **env)
{
	t_shinf	*sh;

	sh = shinf_create(env);
	if (sh == NULL)
		return (84);
	loop(sh);
	return (1);
}
