/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:49:44 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 03:43:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#include "basic.h"
#include "my_printf.h"

#include <errno.h>
#include <string.h>

static int	compare_without_linechange(char *l, char *in, size_t len)
{
	bool	line_change;
	int		status;

	line_change = l[len - 1] == '\n';
	if (line_change)
		l[len - 1] = '\0';
	status = my_strcmp(l, in) == 0;
	if (line_change)
		l[len - 1] = '\n';
	return (status);
}

static int	here_doc(char *in)
{
	struct s_pipe	p;
	char			*l;
	size_t			len;

	if (pipe((int *)&p))
		return (-1);
	while (true)
	{
		l = mini_line(false);
		if (l == NULL)
			break ;
		len = my_strlen(l);
		if (compare_without_linechange(l, in, len))
		{
			free(l);
			break ;
		}
		write(p.write, l, len);
		free(l);
	}
	gnl_flush();
	close(p.write);
	return (p.read);
}

int	open_redir(t_redir redir, char *arg)
{
	int	fd;
	int	flags;

	if (redir == SINGLE_INPUT)
		fd = open(arg, O_RDONLY);
	else if (redir == DUAL_INPUT)
		fd = here_doc(arg);
	else if (redir & 0b001)
	{
		flags = O_WRONLY | O_CREAT;
		if (redir & DUAL)
			flags |= O_APPEND;
		fd = open(arg, flags, 0664);
	}
	else
		fd = -1;
	if (fd < 0)
		my_dprintf(2, "%s: %s.\n", arg, strerror(errno));
	return (fd);
}
