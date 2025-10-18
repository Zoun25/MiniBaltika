/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:41:23 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 14:03:57 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"

bool	node_validate_line(t_node *node)
{
	t_node_line	*n;

	n = (t_node_line *)node;
	return (node_validate(n->a));
}
