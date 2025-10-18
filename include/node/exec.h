/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:39:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 00:08:33 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "node.h"

int	node_exec_nop(t_shinf *sh, t_node *a);
int	node_exec_and(t_shinf *sh, t_node *a);
int	node_exec_or(t_shinf *sh, t_node *a);
int	node_exec_semicolon(t_shinf *sh, t_node *a);
int	node_exec_block(t_shinf *sh, t_node *a);
int	node_exec_proc(t_shinf *sh, t_node *a);
int	node_exec_line(t_shinf *sh, t_node *a);

#endif
