/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:02:37 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/04 02:36:05 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"
#include "basic.h"

t_node	*node_create_block(unsigned int c, t_node_proc **proc)
{
	t_node_block	*n;

	n = my_calloc(1, sizeof(t_node_block));
	if (n == NULL)
		return (NULL);
	n->type.type = BLOCK;
	n->amount = c;
	n->proc = proc;
	n->pipes = my_calloc(sizeof(struct s_pipe), c);
	printf("%u %p\n", c, n->pipes);
	if (n->pipes == NULL)
	{
		node_destroy((t_node *)n);
		return (NULL);
	}
	n->status = (struct s_pipe){-1, -1};
	while (c > 0)
	{
		n->pipes[c - 1].read = -1;
		n->pipes[c - 1].write = -1;
		c --;
	}
	return ((t_node *)n);
}
