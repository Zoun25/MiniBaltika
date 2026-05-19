/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:53:12 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/19 13:48:30 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/parse.h"
#include "node/create.h"

double	node_parse_prio_nop(t_shinf *sh, t_token **token, size_t size)
{
	(void)sh;
	(void)token;
	if (size == 0)
		return (1);
	return (0);
}

t_node	*node_parse_nop(t_shinf *sh, t_token **token, size_t size)
{
	(void)sh;
	(void)token;
	(void)size;
	return (node_create_nop());
}
