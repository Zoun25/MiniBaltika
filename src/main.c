/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:55:22 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 13:11:09 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "input.h"
#include "parse.h"
#include "node.h"
#include "env.h"

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

static void	loop(t_shinf *sh)
{
	char	*line;
	t_node	*tree;

	while (true)
	{
		line = mini_line();
		if (line == NULL)
			break ;
		if (!apply_vars(sh, &line))
			break ;
		tree = parse_line(sh, line);
		if (tree == NULL)
		{
			sh->status_code = 1;
			free(line);
			continue ;
		}
		node_print(tree);
		sh->status_code = node_exec(tree);
		node_destroy(tree);
		free(line);
	}
	free(line);
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
