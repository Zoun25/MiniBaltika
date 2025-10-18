/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 06:23:57 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 20:32:51 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"
#include "my_printf.h"

#include "parse.h"
#include "node/create.h"

static void	move_buff(size_t size, char *buff, bool movement)
{
	char	*pipe;
	size_t	len;

	pipe = my_strchr(buff, '|');
	if (pipe)
		pipe[0] = '\0';
	if (!movement)
		return ;
	len = my_strlen(buff);
	my_memmove(buff, &buff[len + 1], size - len);
}

static unsigned int	count_pipes(char *line, size_t begin, size_t end)
{
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (begin + i < end)
	{
		avoid_quotes(line, &i, begin, end);
		if (line[begin + i] == '|')
			count ++;
		i ++;
	}
	return (count);
}

static void	destroy_procs(t_node **procs)
{
	unsigned int	i;

	i = 0;
	while (procs[i])
	{
		node_destroy(procs[i]);
		i ++;
	}
	free(procs);
}

static t_node	**create_procs(t_shinf *sh, char *line, size_t begin,
							size_t end)
{
	unsigned int	pipes;
	unsigned int	i;
	t_node			**procs;
	char			*buff;

	i = 0;
	pipes = count_pipes(line, begin, end);
	buff = malloc(sizeof(char) * (end - begin + 1));
	if (buff == NULL)
		return (NULL);
	my_memcpy(buff, &line[begin], end - begin);
	buff[end - begin] = '\0';
	procs = my_calloc(pipes + 2, sizeof(t_node *));
	if (procs == NULL)
		return (free(buff), NULL);
	while (i < pipes + 1)
	{
		move_buff(end - begin, buff, false);
		procs[i] = parse_proc(sh, buff);
		move_buff(end - begin, buff, true);
		if (procs[i] == NULL)
			return (free(buff), destroy_procs(procs), NULL);
		i ++;
	}
	return (free(buff), procs);
}

t_node	*parse_block(t_shinf *sh, char *line, size_t begin, size_t end)
{
	unsigned int	pipes;
	t_node			*block;
	t_node			**procs;

	pipes = count_pipes(line, begin, end);
	procs = create_procs(sh, line, begin, end);
	if (procs == NULL)
		return (my_dprintf(2, "Error 12: Failed to malloc"), NULL);
	block = node_create_block((unsigned int)pipes + 1, (t_node_proc **)procs);
	if (block == NULL)
	{
		destroy_procs(procs);
		return (my_dprintf(2, "Error 12: Failed to malloc"), NULL);
	}
	return (block);
}
