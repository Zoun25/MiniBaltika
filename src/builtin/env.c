/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:06:05 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 10:00:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"

#include "my_printf.h"
#include <stdlib.h>

int	mini_env(t_shinf *sh, t_node_proc *proc)
{
	int		fd;
	size_t	i;

	if (proc->argc != 1)
		return (127);
	fd = get_write_fd((t_node_block *)sh->block, proc->id);
	i = 0;
	while (sh->env[i])
	{
		my_dprintf(fd, "%s", sh->env[i]);
		my_dprintf(fd, "\n");
		i ++;
	}
	return (0);
}
