/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:53:12 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/19 19:20:39 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"
#include "node/create.h"

double	node_parse_prio_line(t_shinf *sh, t_token **token, size_t size)
{
	size_t	i;

	(void) sh;
	i = 0;
	while (i < size)
	{
		if (token[i]->type == TOKEN_LINEBREAK)
			return (PRIO_LINE);
		i ++;
	}
	return (0);
}

t_node	*node_parse_line(t_shinf *sh, t_token **token, size_t size)
{
	size_t	len;

	len = 0;
	while (len < size)
	{
		if (token[len]->type == TOKEN_LINEBREAK)
			break ;
		len ++;
	}
	return (node_create_line(node_parse(sh, token, len)));
}
