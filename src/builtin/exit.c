/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:06:05 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/27 05:10:02 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"

#include "basic.h"
#include "my_printf.h"

int	mini_exit(t_shinf *sh, t_node_proc *proc)
{
	if (((t_node_block *)sh->block)->amount != 1)
		return (1);
	if (proc->argc == 1)
		end(sh);
	else if (proc->argc == 2)
	{
		if (!my_str_isnum(proc->argv[1]))
		{
			my_dprintf(2, "numeric argument required: %s\n", proc->argv[1]);
			sh->status_code = 2;
		}
		else
			sh->status_code = my_getnbr(proc->argv[1]);
		end(sh);
	}
	else
	{
		my_dprintf(2, "too many arguments: %d\n", proc->argc - 1);
		return (1);
	}
	return (0);
}
