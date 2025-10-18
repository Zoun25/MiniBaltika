/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:34:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 13:52:24 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/validate.h"

bool	node_validate_and(t_node *node)
{
	t_node_and	*n;

	n = (t_node_and *)node;
	return (node_validate(n->a) && node_validate(n->b));
}
