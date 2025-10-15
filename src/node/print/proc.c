/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:16:25 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 21:48:16 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_print_proc(t_node *node, unsigned int depth)
{
	t_node_proc	*n;
	int			i;

	n = (t_node_proc *)node;
	i = 0;
	print_depth(depth);
	my_printf("%2d:", n->argc);
	while (i < n->argc)
	{
		my_printf(" %s", n->argv[i]);
		i ++;
	}
	my_printf("\n");
}
