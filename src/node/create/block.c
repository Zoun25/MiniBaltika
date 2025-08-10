/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:02:37 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/10 23:58:48 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"
#include "basic.h"

t_node	*node_create_block(int ifd, int ofd, unsigned int c, t_node_proc *proc)
{
	t_node_block	*n;

	n = my_calloc(1, sizeof(t_node_block));
	if (n == NULL)
		return (NULL);
	n->ifd = ifd;
	n->ofd = ofd;
	n->amount = c;
	n->proc = proc;
	return ((t_node *)n);
}
