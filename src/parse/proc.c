/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:14:17 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 03:45:01 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "input.h"
#include "node_create.h"

#include "basic.h"

static void	curate_arg(t_shinf *sh, char **arg)
{
	size_t	len;
	char	ends[2];

	len = my_strlen(*arg);
	ends[0] = (*arg)[0];
	ends[1] = (*arg)[len - 1];
	if ((ends[0] == '\'' || ends[0] == '"') && ends[0] == ends[1])
	{
		my_memmove(*arg, &(*arg)[1], len - 2);
		(*arg)[len - 2] = '\0';
	}
	if (ends[0] != '\'' && ends[1] != '\'')
		apply_vars(sh, arg);
}

static t_redir	get_redir_type(char *arg)
{
	if (my_strcmp(arg, "<") == 0)
		return (SINGLE_INPUT);
	else if (my_strcmp(arg, "<<") == 0)
		return (DUAL_INPUT);
	else if (my_strcmp(arg, ">") == 0)
		return (SINGLE_OUTPUT);
	else if (my_strcmp(arg, ">>") == 0)
		return (DUAL_OUTPUT);
	return (NON);
}

static int	parse_redir(t_shinf *sh, char **args, struct s_pipe *fds)
{
	size_t			i;
	t_redir			redir;

	fds->read = -1;
	fds->write = -1;
	i = 0;
	while (args[i])
	{
		redir = get_redir_type(args[i]);
		i += redir == NON;
		if (redir == NON)
			continue ;
		if (args[i + 1] == NULL)
			return (close_pipe(fds), 0);
		curate_arg(sh, &args[i + 1]);
		if (((int *)fds)[redir & OUTPUT] == -1)
			((int *)fds)[redir & OUTPUT] = open_redir(redir, args[i + 1]);
		if (((int *)fds)[redir & OUTPUT] == -1)
			return (close_pipe(fds), 0);
		free(args[i]);
		free(args[i + 1]);
		my_memmove(&args[i], &args[i + 2], sizeof(char *) * \
			(get_pointer_array_len(args) - i - 1));
	}
	return (1);
}

t_node	*parse_proc(t_shinf *sh, char *line)
{
	t_node			*proc;
	char			**splited;
	struct s_pipe	redirs;
	size_t			i;

	splited = my_coolersplit(line, " \t");
	if (splited == NULL)
		return (NULL);
	if (!parse_redir(sh, splited, &redirs))
		return (free_string_array(splited), NULL);
	i = 0;
	while (splited[i])
	{
		curate_arg(sh, &splited[i]);
		i ++;
	}
	proc = node_create_proc(get_pointer_array_len(splited), splited, redirs);
	if (proc == NULL)
		free_string_array(splited);
	return (proc);
}
