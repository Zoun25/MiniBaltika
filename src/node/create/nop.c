/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:09:33 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/07 00:31:20 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_create.h"
#include "basic.h"

t_node	*node_create_nop(void)
{
	t_node_nop	*n;

	n = my_calloc(1, sizeof(t_node_nop));
	if (n == NULL)
		return (NULL);
	return ((t_node *)n);
}
