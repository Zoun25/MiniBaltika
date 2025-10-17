/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:16:25 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 03:31:38 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_destroy.h"
#include "basic.h"
#include "input.h"

void	node_destroy_proc(t_node *node)
{
	t_node_proc	*n;

	n = (t_node_proc *)node;
	free_string_array(n->argv);
	close_pipe(&n->fds);
}
