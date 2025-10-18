/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:13:30 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 13:52:45 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"

bool	node_validate_or(t_node *node)
{
	t_node_or	*n;

	n = (t_node_or *)node;
	return (node_validate(n->a) && node_validate(n->b));
}
