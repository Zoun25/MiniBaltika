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

int	node_exec_or(t_node *node)
{
	t_node_or	*n;
	int			status;

	n = (t_node_or *)node;
	status = node_exec(n->a);
	if (status != 0)
	{
		return (node_exec(n->b));
	}
	else
	{
		return (status);
	}
}
