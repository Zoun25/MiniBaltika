/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:14:17 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/29 13:04:09 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "input.h"
#include "node/create.h"
#include "env.h"

#include "basic.h"
#include "my_printf.h"

static char	*remove_quotes(char *line, int pos)
{
	int		p2;

	while (line[pos])
	{
		if (line[pos] == '\'' || line[pos] == '"')
			break ;
		pos ++;
	}
	if (line[pos] != '\'' && line[pos] != '"')
		return (line);
	p2 = pos;
	avoid_quotes(line, &p2, 0, my_strlen(line));
	p2 --;
	my_memmove(&line[pos], &line[pos + 1], p2 - pos - 1);
	my_memmove(&line[p2 - 1], &line[p2 + 1], my_strlen(&line[p2 + 1]));
	line[my_strlen(line) - 2] = '\0';
	my_printf("%s\n", line);
	return (remove_quotes(line, p2 - 1));
}

static void	curate_arg(t_shinf *sh, char **arg)
{
	apply_vars(sh, arg);
	*arg = remove_quotes(*arg, 0);
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
		return (my_dprintf(2, "failed split: `%s`\n\t(posible open quote)\n",
				line), NULL);
	if (get_pointer_array_len((void *)splited) == 0)
		return (node_create_nop());
	if (!parse_redir(sh, splited, &redirs))
		return (my_dprintf(2, "syntax error: invalid redirection")
			, free_string_array(splited), NULL);
	i = 0;
	while (splited[i])
	{
		curate_arg(sh, &splited[i]);
		i ++;
	}
	proc = node_create_proc(get_pointer_array_len(splited), splited, redirs,
			get_executable(sh, splited[0]));
	if (proc == NULL)
		free_string_array(splited);
	return (proc);
}
