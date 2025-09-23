/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:41:23 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/16 23:56:53 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

int	node_exec_line(t_node *node)
{
	t_node_line	*n;

	n = (t_node_line *)node;
	return (node_exec(n->a));
}
