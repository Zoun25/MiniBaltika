/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:41:23 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 01:14:16 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/exec.h"

int	node_exec_line(t_shinf *sh, t_node *node)
{
	t_node_line	*n;
	int			status;

	n = (t_node_line *)node;
	sh->line = node;
	status = node_exec(sh, n->a);
	sh->line = NULL;
	return (status);
}
