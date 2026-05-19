/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:53:12 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/19 20:04:46 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"
#include "node/create.h"

double	node_parse_prio_semicolon(t_shinf *sh, t_token **token, size_t size)
{
	size_t	i;

	(void)sh;
	i = 0;
	while (i < size)
	{
		if (token[i]->type == TOKEN_SEMICOLON)
			return (PRIO_SEMICOLON);
		i ++;
	}
	return (0);
}

t_node	*node_parse_semicolon(t_shinf *sh, t_token **token, size_t size)
{
	size_t	semi;

	semi = 0;
	while (semi < size)
	{
		if (token[semi]->type == TOKEN_LINEBREAK)
			break ;
		semi ++;
	}
	if (semi == size)
		return (NULL);
	return (node_create_semicolon(
			node_parse(sh, token, semi),
			node_parse(sh, &token[semi + 1], size - semi - 1)
		));
}
