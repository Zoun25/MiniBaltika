/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:54:30 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/05 01:46:21 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stddef.h>

enum e_node_type
{
	NOP,
	AND,
	OR,
	SEMICOLON,
	BLOCK,
	PROC,
	LINE,
};

typedef struct node
{
	enum e_node_type	type;
}	t_node;

typedef t_node		t_zero;

typedef struct simple_node
{
	t_node	type;
	t_node	*a;
}	t_simple;

typedef struct double_node
{
	t_node	type;
	t_node	*a;
	t_node	*b;
}	t_double;

typedef struct process_node
{
	t_node	type;
	int		argc;
	char	**argv;
}	t_node_proc;

typedef struct block_node
{
	t_node		type;
	size_t		amount;
	t_node		*proc;
}	t_node_block;

typedef t_double	t_node_and;
typedef t_double	t_node_or;
typedef t_double	t_node_semicolon;
typedef t_simple	t_node_line;

void	node_print(t_node *node);

#endif
