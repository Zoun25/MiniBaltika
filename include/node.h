/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:54:30 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/13 18:28:02 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stddef.h>

# include "builtin/list.h"

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
	t_node			type;
	int				argc;
	char			**argv;
	char			*path;
	t_builtin_id	builtin;
}	t_node_proc;

typedef struct block_node
{
	t_node		type;
	int			ifd;
	int			ofd;
	size_t		amount;
	t_node_proc	*proc;
}	t_node_block;

typedef t_double	t_node_and;
typedef t_double	t_node_or;
typedef t_double	t_node_semicolon;
typedef t_simple	t_node_line;
typedef t_zero		t_node_nop;

t_node	*node_create(enum e_node_type type, ...);
void	node_print(t_node *node);
int		node_exec(t_node *node);
void	node_destroy(t_node *node);

#endif
