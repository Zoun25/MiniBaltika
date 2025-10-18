/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:06:05 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 10:03:28 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"

#include "my_printf.h"
#include "basic.h"

#include <stdbool.h>

int	mini_echo(t_shinf *sh, t_node_proc *proc)
{
	bool	line;
	int		fd;
	int		i;
	char	*sep;

	line = true;
	i = 1;
	if (proc->argc > 1 && proc->argv[i][0] == '-' && \
		my_strchr_count(proc->argv[i], 'n') + 1 == my_strlen(proc->argv[i]))
	{
		line = false;
		i ++;
	}
	fd = get_write_fd((t_node_block *)sh->block, proc->id);
	sep = " ";
	while (i < proc->argc)
	{
		if (i + 1 == proc->argc)
			sep = "";
		my_dprintf(fd, "%s%s", proc->argv[i], sep);
		i ++;
	}
	if (line)
		my_dprintf(fd, "\n");
	return (0);
}
