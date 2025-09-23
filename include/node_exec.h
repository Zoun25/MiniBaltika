/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/16 23:19:47 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_EXEC_H
# define NODE_EXEC_H

# include "node.h"

int	node_exec_nop(t_node *a);
int	node_exec_and(t_node *a);
int	node_exec_or(t_node *a);
int	node_exec_semicolon(t_node *a);
int	node_exec_block(t_node *a);
int	node_exec_proc(t_node *a);
int	node_exec_line(t_node *a);

#endif
