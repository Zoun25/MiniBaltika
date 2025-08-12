/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:41:23 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/12 02:55:23 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_destroy_line(t_node *node)
{
	t_node_line	*n;

	n = (t_node_line *)node;
	node_destroy(n->a);
}
