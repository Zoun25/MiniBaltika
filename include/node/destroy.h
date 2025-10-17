/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 05:16:31 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H

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
