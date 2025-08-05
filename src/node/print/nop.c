/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:09:33 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/04 22:16:03 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_print.h"

void	node_print_nop(t_node __attribute__((unused))*node, unsigned int depth)
{
	print_depth(depth);
	my_printf("%s\n", "NOP");
}
