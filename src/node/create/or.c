/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:13:30 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/06 03:15:35 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_create.h"
#include "basic.h"

t_node	*node_create_or(t_node *a, t_node *b)
{
	t_node_or	*n;

	n = my_calloc(1, sizeof(t_node_or));
	if (n == NULL)
		return (NULL);
	n->a = a;
	n->b = b;
	return ((t_node *)n);
}
