/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:14:09 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/12 02:55:00 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_destroy_semicolon(t_node *node)
{
	t_node_semicolon	*n;

	n = (t_node_semicolon *)node;
	node_destroy(n->a);
	node_destroy(n->b);
}
