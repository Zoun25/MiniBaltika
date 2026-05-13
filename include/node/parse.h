/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:56:49 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/13 22:43:26 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "node.h"

struct s_priority_index
{
	double	priority;
	size_t	index;
};

double	node_parse_prio_nop(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_nop(t_shinf *sh, t_token **token, size_t size);

double	node_parse_prio_and(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_and(t_shinf *sh, t_token **token, size_t size);

double	node_parse_prio_or(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_or(t_shinf *sh, t_token **token, size_t size);

double	node_parse_prio_semicolon(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_semicolon(t_shinf *sh, t_token **token, size_t size);

double	node_parse_prio_block(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_block(t_shinf *sh, t_token **token, size_t size);

double	node_parse_prio_proc(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_proc(t_shinf *sh, t_token **token, size_t size);

double	node_parse_prio_line(t_shinf *sh, t_token **token, size_t size);
t_node	*node_parse_line(t_shinf *sh, t_token **token, size_t size);

#endif
