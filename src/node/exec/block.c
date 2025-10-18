/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:02:37 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 10:38:49 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/exec.h"
#include "builtin/funcs.h"
#include "input.h"

#include "my_printf.h"

static size_t	forking(t_shinf *sh, t_node_block *n)
{
	size_t	i;
	pid_t	pid;

	i = 0;
	while (i < n->amount)
	{
		if (n->proc[i]->exec.builtin != NONE)
		{
			i ++;
			continue ;
		}
		pid = fork();
		if (pid > 0)
			n->proc[i]->pid = pid;
		else if (pid == 0)
		{
			n->proc[i]->id = i;
			node_exec(sh, (t_node *)n->proc[i]);
			exit(84);
		}
		else
			return (i);
		i ++;
	}
	return (n->amount);
}

static int	fork_proccesses(t_shinf *sh, t_node_block *n)
{
	size_t	i;
	char	status;

	n->active = forking(sh, n);
	if (n->active == n->amount)
		status = 't';
	else
		status = 'f';
	i = 0;
	while (i < n->active)
	{
		write(n->status.write, &status, 1);
		i ++;
	}
	return (status == 't');
}

static int	create_pipes(t_node_block *n)
{
	size_t	i;

	i = 0;
	if (pipe((int *)&n->status) < 0)
		return (0);
	while (i < n->amount - 1)
	{
		if (pipe((int *)&n->pipes[i]) < 0)
			return (0);
		i ++;
	}
	return (1);
}

int	node_exec_block(t_shinf *sh, t_node *node)
{
	t_node_block	*n;

	n = (t_node_block *)node;
	if (!create_pipes(n))
		return (1);
	sh->block = node;
	if (!fork_proccesses(sh, n))
		return (1);
	manage_children(sh, n);
	sh->block = NULL;
	return (n->proc[n->amount - 1]->exit_status);
}
