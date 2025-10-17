/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:09:33 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 04:27:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/create.h"
#include "basic.h"

t_node	*node_create_nop(void)
{
	t_node_nop	*n;

	n = my_calloc(1, sizeof(t_node_nop));
	if (n == NULL)
		return (NULL);
	n->type = NOP;
	return ((t_node *)n);
}
