/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:53:12 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/19 20:03:59 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"
#include "node/create.h"

double	node_parse_prio_and(t_shinf *sh, t_token **token, size_t size)
{
	size_t	i;

	(void)sh;
	i = 0;
	while (i < size)
	{
		if (token[i]->type == TOKEN_AND)
			return (PRIO_AND);
		i ++;
	}
	return (0);
}

t_node	*node_parse_and(t_shinf *sh, t_token **token, size_t size)
{
	size_t	and;

	and = size;
	while (and > 0)
	{
		if (token[and - 1]->type == TOKEN_AND)
			break ;
		and --;
	}
	if (and == 0)
		return (NULL);
	return (node_create_and(
			node_parse(sh, token, and - 1),
			node_parse(sh, &token[and], size - and)
		));
}
