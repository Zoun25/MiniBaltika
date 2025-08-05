/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:34:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/05 02:27:11 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_print_and(t_node *node, unsigned int depth)
{
	t_node_and	*n;

	n = (t_node_and *)node;
	node_print_depth(n->a, depth + 1);
	print_depth(depth);
	my_printf("%s\n", "&&");
	node_print_depth(n->b, depth + 1);
}
