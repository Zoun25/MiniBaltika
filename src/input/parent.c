/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 02:03:16 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 20:20:08 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "node.h"
#include "input.h"
#include "builtin/funcs.h"

#include "my_printf.h"

#include <sys/wait.h>
#include <errno.h>
#include <string.h>

static void	close_fds(t_node_block *block, size_t id, bool reader)
{
	if (id != 0 && reader)
	{
		close(block->pipes[id - 1].read);
		block->pipes[id - 1].read = -1;
	}
	if (id != block->amount - 1)
	{
		close(block->pipes[id].write);
		block->pipes[id].write = -1;
	}
}

static ssize_t	get_id_by_pid(t_node_block *block, pid_t pid)
{
	size_t	i;

	i = 0;
	if (pid == -1)
		return (pid);
	while (i < block->amount)
	{
		if (block->proc[i]->pid == pid)
			return (i);
		i ++;
	}
	return (-1);
}

static void	manage_wstatus(t_node_proc *c, int wstatus)
{
	if (WIFEXITED(wstatus))
		c->exit_status = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	{
		my_dprintf(2, "killed by signal:\n sig:%d \n core dump:%d\n",
			WTERMSIG(wstatus), WCOREDUMP(wstatus) != 0);
		c->exit_status = 128 + WTERMSIG(wstatus);
	}
	else
	{
		my_dprintf(2, "Child process exited abnormally\n");
		c->exit_status = 1;
	}
}

void	manage_children(t_shinf *sh, t_node_block *block)
{
	ssize_t	id;
	size_t	i;
	int		wstatus;

	i = 0;
	while (i < block->amount)
	{
		if (block->proc[i]->exec.builtin != NONE)
		{
			mini_builtin(sh, block->proc[i]);
			close_fds(block, i, false);
			block->active --;
		}
		i ++;
	}
	while (block->active > 0)
	{
		id = get_id_by_pid(block, wait(&wstatus));
		if (id < 0)
			continue ;
		close_fds(block, id, true);
		manage_wstatus(block->proc[id], wstatus);
		block->active --;
	}
}
