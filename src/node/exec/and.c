/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:34:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/16 23:53:47 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_exec.h"

int	node_exec_and(t_node *node)
{
	t_node_and	*n;
	int			status;

	n = (t_node_and *)node;
	status = node_exec(n->a);
	if (status == 0)
	{
		return (node_exec(n->b));
	}
	else
	{
		return (status);
	}
}
