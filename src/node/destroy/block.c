/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:02:37 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/12 02:53:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_destroy_block(t_node *node)
{
	t_node_block	*n;
	unsigned int	i;

	n = (t_node_block *)node;
	i = 0;
	while (i < n->amount)
	{
		node_destroy((t_node *)&n->proc[i]);
		i ++;
	}
}
