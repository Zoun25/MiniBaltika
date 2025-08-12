/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:34:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/06 03:43:48 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_destroy.h"

void	node_destroy_and(t_node *node)
{
	t_node_and	*n;

	n = (t_node_and *)node;
	node_destroy(n->a);
	node_destroy(n->b);
}
