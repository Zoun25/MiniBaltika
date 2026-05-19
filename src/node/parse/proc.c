/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:53:12 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/19 20:05:05 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"
#include "node/create.h"

double	node_parse_prio_proc(t_shinf *sh, t_token **token, size_t size)
{
	size_t	i;

	(void)sh;
	i = 0;
	while (i < size)
	{
		if (!(token[i]->type & (TOKEN_WORD | TOKEN_REDIRECTION)))
			return (0);
		i ++;
	}
	return (PRIO_BLOCK);
}

t_node	*node_parse_proc(t_shinf *sh, t_token **token, size_t size)
{
	(void)sh;
	(void)token;
	(void)size;
	return (node_create_nop());
}
