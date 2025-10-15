/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:14:09 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 20:47:21 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_create.h"
#include "basic.h"

t_node	*node_create_semicolon(t_node *a, t_node *b)
{
	t_node_semicolon	*n;

	n = my_calloc(1, sizeof(t_node_semicolon));
	if (n == NULL)
		return (NULL);
	n->type.type = SEMICOLON;
	n->a = a;
	n->b = b;
	return ((t_node *)n);
}
