/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:14:09 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 14:02:02 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/print.h"

bool	node_validate_semicolon(t_node *node)
{
	t_node_semicolon	*n;

	n = (t_node_semicolon *)node;
	return (node_validate(n->a) && node_validate(n->b));
}
