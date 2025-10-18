/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 01:30:35 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 01:32:00 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_is_sq(char *line, int pos)
{
	bool	sq;
	bool	dq;
	int		i;

	sq = 0;
	dq = 0;
	i = 0;
	if (!line)
		return (0);
	while (line[i] && i < pos)
	{
		if (!line[i])
			return (sq);
		if (line[i] == '\"' && !dq)
			dq = !dq;
		else if (line[i] == '\"' && dq)
			dq = !dq;
		if (line[i] == '\'' && !dq && !sq)
			sq = !sq;
		else if (line[i] == '\'' && !dq && sq)
			sq = !sq;
		i++;
	}
	return (sq);
}
