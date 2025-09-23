/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:56:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/16 23:54:12 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_exec.h"

int	node_exec(t_node *node)
{
	static int	(*execer[])(t_node *) = {
		&node_exec_nop, &node_exec_and, &node_exec_or,
		&node_exec_semicolon, &node_exec_block, &node_exec_proc,
		&node_exec_line
	};

	return (execer[node->type](node));
}
