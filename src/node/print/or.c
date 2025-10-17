/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:13:30 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 04:27:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"

void	node_print_or(t_node *node, unsigned int depth)
{
	t_node_or	*n;

	n = (t_node_or *)node;
	node_print_depth(n->a, depth + 1);
	print_depth(depth);
	my_printf("%s\n", "||");
	node_print_depth(n->b, depth + 1);
}
