/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:34:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 04:27:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/create.h"
#include "basic.h"

t_node	*node_create_and(t_node *a, t_node *b)
{
	t_node_and	*n;

	n = my_calloc(1, sizeof(t_node_and));
	if (n == NULL)
		return (NULL);
	n->type.type = AND;
	n->a = a;
	n->b = b;
	return ((t_node *)n);
}
