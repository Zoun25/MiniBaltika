/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:14:09 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/16 23:55:31 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

int	node_exec_semicolon(t_node *node)
{
	t_node_semicolon	*n;

	n = (t_node_semicolon *)node;
	node_exec(n->a);
	return (node_exec(n->b));
}
