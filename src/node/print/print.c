/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:56:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 04:27:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"

void	print_depth(unsigned int depth)
{
	unsigned int	i;

	i = 0;
	while (i < depth)
	{
		my_printf("%s", "    ");
		i ++;
	}
}

void	node_print_depth(t_node *node, unsigned int depth)
{
	static void	(*printer[])(t_node *, unsigned int) = {
		&node_print_nop, &node_print_and, &node_print_or, &node_print_semicolon,
		&node_print_block, &node_print_proc, &node_print_line
	};

	printer[node->type](node, depth);
}

void	node_print(t_node *node)
{
	node_print_depth(node, 0);
}
