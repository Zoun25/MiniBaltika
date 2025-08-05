/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:58:54 by angsanch          #+#    #+#             */
/*   Updated: 2025/08/04 22:21:31 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>

typedef struct command
{
	int		argc;
	char	**argv;
	pid_t	pid;
	int		exit_status;
	char	*path;
	void	(*builtin)(void);
}	t_command;

typedef struct line
{
	unsigned int	amount;
	struct command	*command;
	int				in_fd;
	int				out_fd;
	int				exit_status;
}	t_line;

char	*mini_getline(int fd);//returns null on error or eof
t_line	*line_prepare(const char *str);
int		line_populate(t_line *line);
int		execute(t_line *line);

void	command_delete(t_command *command);
void	line_delete(t_line *line);

#endif
