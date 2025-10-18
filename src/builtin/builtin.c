/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:56:14 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 09:59:16 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"

int	get_write_fd(t_node_block *block, size_t id)
{
	int	fd;

	fd = block->proc[id]->fds.write;
	if (fd >= 0)
		return (fd);
	if (id + 1 == block->amount)
		return (1);
	return (block->pipes[id].write);
}

int	mini_builtin(t_shinf *sh, t_node_proc *proc)
{
	static int	(*funcs[])(t_shinf *, t_node_proc *) = {NULL, mini_echo,
		mini_cd, mini_pwd, mini_export, mini_unset, mini_env,
		mini_exit};

	if (proc->exec.builtin == NONE)
		return (0);
	proc->exit_status = funcs[proc->exec.builtin](sh, proc);
	return (1);
}
