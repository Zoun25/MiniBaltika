/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 04:12:16 by angsanch          #+#    #+#             */
/*   Updated: 2026/02/17 22:01:36 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "basic.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

static int	g_interrupt;

static void	my_g_interrupt(int signum)
{
	g_interrupt = signum;
	if (signum == 2)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

char	*mini_line(t_shinf *sh, bool print)
{
	char	*line;
	char	*promt;

	promt = "";
	if (print)
		promt = "baltika$ ";
	if (isatty(0))
	{
		signal(SIGINT, my_g_interrupt);
		signal(SIGQUIT, SIG_IGN);
		g_interrupt = 0;
		line = readline(promt);
		if (g_interrupt)
			sh->status_code = 128 + g_interrupt;
		if (line)
		{
			if (my_strlen(line))
				add_history(line);
		}
		return (line);
	}
	else
	{
		return (get_next_line(0));
	}
}
