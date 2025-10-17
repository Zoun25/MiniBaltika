/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:16:25 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 03:30:45 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"
#include "basic.h"

t_node	*node_create_proc(int argc, char **argv, struct s_pipe pipe)
{
	t_node_proc	*n;

	n = my_calloc(1, sizeof(t_node_proc));
	if (n == NULL)
		return (NULL);
	n->type.type = PROC;
	n->argc = argc;
	n->argv = argv;
	n->fds = pipe;
	return ((t_node *)n);
}
