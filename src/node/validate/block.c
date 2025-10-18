/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:02:37 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 14:33:28 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"
#include "input.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

bool	node_validate_block(t_node *node)
{
	t_node_block	*n;
	unsigned int	i;

	n = (t_node_block *)node;
	i = 0;
	while (i < n->amount)
	{
		if (n->proc[i] == NULL)
			return (my_dprintf(2, "%s %s: %s\n", "Error"
					, strerror(errno)), "Failed to malloc", 0);
		if (n->proc[i]->type.type != PROC)
			return (my_dprintf(2, "%s 10: %s\n", "Error",
					"Exec format error"), false);
		if (!node_validate((t_node *)n->proc[i]))
			return (false);
		i ++;
	}
	if (n->amount == 0)
		return (my_dprintf(2, "Error 9: Bad address\n"), false);
	return (true);
}
