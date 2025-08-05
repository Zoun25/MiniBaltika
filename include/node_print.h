/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_print.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/04 23:46:49 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_PRINT_H
# define NODE_PRINT_H

# include "node.h"
# include "my_printf.h"

void	print_depth(unsigned int depth);

void	node_print_nop(t_node *node, unsigned int depth);
void	node_print_and(t_node *node, unsigned int depth);
void	node_print_or(t_node *node, unsigned int depth);
void	node_print_semicolon(t_node *node, unsigned int depth);
void	node_print_block(t_node *node, unsigned int depth);
void	node_print_proc(t_node *node, unsigned int depth);
void	node_print_line(t_node *node, unsigned int depth);

void	node_print_depth(t_node *node, unsigned int depth);

#endif
