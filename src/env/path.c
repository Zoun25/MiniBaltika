/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 04:52:03 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 05:30:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

#include "basic.h"

int	update_path(t_shinf *sh, char *path)
{
	char	**parts;
	size_t	i;
	size_t	len;

	parts = my_split(path, ':');
	if (parts == NULL)
		return (0);
	free_string_array(sh->path.path);
	sh->path.path = parts;
	sh->path.longest = 0;
	i = 0;
	while (parts[i])
	{
		len = my_strlen(parts[i]);
		if (len > sh->path.longest)
			sh->path.longest = len;
		i ++;
	}
	return (1);
}
