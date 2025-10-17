/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 05:03:21 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

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
