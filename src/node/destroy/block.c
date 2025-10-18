/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:02:37 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 00:58:27 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"
#include "input.h"

#include <stdlib.h>

void	node_destroy_block(t_node *node)
{
	t_node_block	*n;
	unsigned int	i;

	n = (t_node_block *)node;
	i = 0;
	while (i < n->amount)
	{
		node_destroy((t_node *)n->proc[i]);
		if (i + 1 < n->amount)
			close_pipe(&n->pipes[i]);
		i ++;
	}
	close_pipe(&n->status);
	free(n->proc);
	free(n->pipes);
}
