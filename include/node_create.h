/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_create.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/10 23:55:53 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_CREATE_H
# define NODE_CREATE_H

# include "node.h"

t_node	*node_create_nop(void);
t_node	*node_create_and(t_node *a, t_node *b);
t_node	*node_create_or(t_node *a, t_node *b);
t_node	*node_create_semicolon(t_node *a, t_node *b);
t_node	*node_create_block(int ifd, int ofd, unsigned int c, t_node_proc *proc);
t_node	*node_create_proc(int argc, char **argv);
t_node	*node_create_line(t_node *a);

t_node	*node_create_double(t_node *a, t_node *b);

#endif
