/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:41:23 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/06 03:32:57 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_create.h"
#include "basic.h"

t_node	*node_create_line(t_node *a)
{
	t_node_line	*n;

	n = my_calloc(1, sizeof(t_node_line));
	if (n == NULL)
		return (NULL);
	n->a = a;
	return ((t_node *)n);
}
