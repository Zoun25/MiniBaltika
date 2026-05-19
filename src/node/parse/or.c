/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:53:12 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/19 20:04:22 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"
#include "node/create.h"

double	node_parse_prio_or(t_shinf *sh, t_token **token, size_t size)
{
	size_t	i;

	(void)sh;
	i = 0;
	while (i < size)
	{
		if (token[i]->type == TOKEN_OR)
			return (PRIO_OR);
		i ++;
	}
	return (0);
}

t_node	*node_parse_or(t_shinf *sh, t_token **token, size_t size)
{
	size_t	or;

	or = size;
	while (or > 0)
	{
		if (token[or - 1]->type == TOKEN_OR)
			break ;
		or --;
	}
	if (or == 0)
		return (NULL);
	return (node_create_or(
			node_parse(sh, token, or - 1),
			node_parse(sh, &token[or], size - or)
		));
}
