/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:56:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 04:27:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/destroy.h"

void	node_destroy(t_node *node)
{
	static void	(*destroyer[])(t_node *) = {
		&node_destroy_nop, &node_destroy_and, &node_destroy_or,
		&node_destroy_semicolon, &node_destroy_block, &node_destroy_proc,
		&node_destroy_line
	};

	if (node == NULL)
		return ;
	destroyer[node->type](node);
	free(node);
}
