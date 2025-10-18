/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:16:25 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 14:32:59 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/validate.h"
#include "basic.h"
#include "input.h"

#include "my_printf.h"

bool	node_validate_proc(t_node *node)
{
	t_node_proc	*n;

	n = (t_node_proc *)node;
	if (get_pointer_array_len(n->argv) != (size_t)n->argc)
		return (my_dprintf(2, "%s\n", "argv len does not match argc"), false);
	if (n->exec.bin && n->exec.builtin)
		return (my_dprintf(2, "%s\n", "proc is builtin and binary"), false);
	return (true);
}
