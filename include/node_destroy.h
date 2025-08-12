/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_destroy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/06 03:40:21 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_DESTROY_H
# define NODE_DESTROY_H

# include "node.h"
# include <stdlib.h>

void	node_destroy_nop(t_node *node);
void	node_destroy_and(t_node *node);
void	node_destroy_or(t_node *node);
void	node_destroy_semicolon(t_node *node);
void	node_destroy_block(t_node *node);
void	node_destroy_proc(t_node *node);
void	node_destroy_line(t_node *node);

#endif
