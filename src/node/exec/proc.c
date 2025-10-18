/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:16:25 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 19:14:30 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/exec.h"
#include "input.h"

#include "basic.h"
#include "my_printf.h"

static int	override_fd(int new, int used)
{
	close(used);
	return (dup2(new, used));
}

static int	prepare_env(t_shinf *sh, t_node_proc *proc)
{
	int				status;
	t_node_block	*block;

	block = ((t_node_block *)sh->block);
	if (proc->fds.read <= 0)
	{
		status = 0;
		if (proc->id != 0)
			status = override_fd(block->pipes[proc->id - 1].read, 0);
	}
	else
		status = override_fd(proc->fds.read, 0);
	if (status < 0)
		return (0);
	if (proc->fds.write <= 0)
	{
		status = 0;
		if (proc->id + 1 != block->amount)
			status = override_fd(block->pipes[proc->id].write, 1);
	}
	else
		status = override_fd(proc->fds.write, 1);
	if (status < 0)
		return (0);
	return (1);
}

static void	close_pipes(t_node_block *block)
{
	size_t	i;

	i = 0;
	while (i < block->amount - 1)
	{
		close_pipe(&block->pipes[i]);
		i ++;
	}
	close_pipe(&block->status);
}

int	node_exec_proc(t_shinf *sh, t_node *node)
{
	t_node_proc	*n;
	char		status;

	n = (t_node_proc *)node;
	child_signals();
	if (read(((t_node_block *)sh->block)->status.read, &status, 1) < 1)
		exit(84);
	if (status == 'f')
		exit(84);
	if (!prepare_env(sh, n))
		exit(84);
	close_pipes((t_node_block *)sh->block);
	if (n->exec.bin == NULL)
		return (1);
	execve(n->exec.bin, n->argv, sh->env);
	return (0);
}
