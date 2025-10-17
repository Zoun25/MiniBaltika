/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:16:25 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 05:20:11 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/destroy.h"
#include "basic.h"
#include "input.h"

void	node_destroy_proc(t_node *node)
{
	t_node_proc	*n;

	n = (t_node_proc *)node;
	free_string_array(n->argv);
	free(n->exec.bin);
	close_pipe(&n->fds);
}
