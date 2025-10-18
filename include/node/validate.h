/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:29:35 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 13:46:10 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "node.h"

# include <stdbool.h>

bool	node_validate_nop(t_node *node);
bool	node_validate_and(t_node *node);
bool	node_validate_or(t_node *node);
bool	node_validate_semicolon(t_node *node);
bool	node_validate_block(t_node *node);
bool	node_validate_proc(t_node *node);
bool	node_validate_line(t_node *node);

#endif
