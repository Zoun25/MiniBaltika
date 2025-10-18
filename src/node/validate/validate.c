/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:56:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 14:42:27 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/validate.h"

#include "my_printf.h"

bool	node_validate(t_node *node)
{
	static bool	(*validator[])(t_node *) = {
		&node_validate_nop, &node_validate_and, &node_validate_or,
		&node_validate_semicolon, &node_validate_block, &node_validate_proc,
		&node_validate_line
	};

	if (node == NULL)
		return (my_dprintf(2, "%s\n", "node is null"), false);
	return (validator[node->type](node));
}
