/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:56:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/12 02:57:38 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_destroy.h"

void	node_destroy(t_node *node)
{
	static void	(*destroyer[])(t_node *) = {
		&node_destroy_nop, &node_destroy_and, &node_destroy_or,
		&node_destroy_semicolon, &node_destroy_block, &node_destroy_proc,
		&node_destroy_line
	};

	destroyer[node->type](node);
	free(node);
}
