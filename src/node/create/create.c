/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:56:02 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/11 00:03:17 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_create.h"
#include <stdarg.h>

t_node	*node_create(enum e_node_type type, ...)
{
	va_list	ap;
	t_node	*result;

	va_start(ap, type);
	if (type == NOP)
		result = node_create_nop();
	else if (type == AND)
		result = node_create_and(va_arg(ap, t_node *), va_arg(ap, t_node *));
	else if (type == OR)
		result = node_create_or(va_arg(ap, t_node *), va_arg(ap, t_node *));
	else if (type == SEMICOLON)
		result = node_create_semicolon(va_arg(ap, t_node *),
				va_arg(ap, t_node *));
	else if (type == BLOCK)
		result = node_create_block(va_arg(ap, int), va_arg(ap, int),
				va_arg(ap, unsigned int), va_arg(ap, t_node_proc *));
	else if (type == PROC)
		result = node_create_proc(va_arg(ap, int), va_arg(ap, char **));
	else if (type == LINE)
		result = node_create_line(va_arg(ap, t_node *));
	else
		result = NULL;
	va_end(ap);
	result->type = type;
	return (result);
}
