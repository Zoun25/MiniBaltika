/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:13:30 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/12 02:54:28 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_destroy_or(t_node *node)
{
	t_node_or	*n;

	n = (t_node_or *)node;
	node_destroy(n->a);
	node_destroy(n->b);
}
