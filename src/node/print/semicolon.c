/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:14:09 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/05 02:17:26 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_print_semicolon(t_node *node, unsigned int depth)
{
	t_node_semicolon	*n;

	n = (t_node_semicolon *)node;
	node_print_depth(n->a, depth + 1);
	print_depth(depth);
	my_printf("%s\n", ";");
	node_print_depth(n->b, depth + 1);
}
