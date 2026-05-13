/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:31:22 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/13 22:43:49 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"

t_node	*node_parse(t_shinf *sh, t_token **tokens, size_t size)
{
	static t_node			*(*parser[])(t_shinf *, t_token **, size_t) = {
		&node_parse_nop, &node_parse_and, &node_parse_or,
		&node_parse_semicolon, &node_parse_block, &node_parse_proc,
		&node_parse_line
	};
	static double			(*priority[])(t_shinf *, t_token **, size_t) = {
		&node_parse_prio_nop, &node_parse_prio_and, &node_parse_prio_or,
		&node_parse_prio_semicolon, &node_parse_prio_block,
		&node_parse_prio_proc, &node_parse_prio_line
	};
	struct s_priority_index	max;
	struct s_priority_index	loop;

	max = (struct s_priority_index){0, 0};
	loop = (struct s_priority_index){0, 0};
	while (loop.index < sizeof(priority) / sizeof(priority[0]))
	{
		loop.priority = priority[loop.index](sh, tokens, size);
		if (loop.priority > max.priority)
			max = loop;
		loop.index ++;
	}
	if (max.priority <= 0)
		return (NULL);
	return (parser[max.index](sh, tokens, size));
}
