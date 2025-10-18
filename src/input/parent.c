/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 02:03:16 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 03:35:29 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "node.h"
#include "input.h"

#include <sys/wait.h>

static void	close_fds(t_node_block *block, size_t id)
{
	if (id != 0)
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
		c->exit_status = 128 + WTERMSIG(wstatus);
	}
	else
		c->exit_status = 1;
}

void	manage_children(t_node_block *block)
{
	ssize_t	id;
	size_t	i;
	int		wstatus;

	i = 0;
	while (i < block->amount)
	{
		if (block->proc[i]->exec.builtin != NONE)
			block->active --;
		i ++;
	}
	while (block->active > 0)
	{
		id = get_id_by_pid(block, wait(&wstatus));
		if (id < 0)
			continue ;
		close_fds(block, id);
		manage_wstatus(block->proc[id], wstatus);
		block->active --;
	}
}
