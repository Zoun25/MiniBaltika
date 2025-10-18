/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:14:09 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 01:13:59 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/exec.h"

int	node_exec_semicolon(t_shinf *sh, t_node *node)
{
	t_node_semicolon	*n;

	n = (t_node_semicolon *)node;
	node_exec(sh, n->a);
	return (node_exec(sh, n->b));
}
