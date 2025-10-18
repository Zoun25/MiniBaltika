/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 04:12:16 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 20:15:42 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "basic.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

static void	ft_sigint(int __attribute__((unused))signum)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*mini_line(bool print)
{
	char	*line;
	char	*promt;

	promt = "";
	if (print)
		promt = "baltika$ ";
	if (isatty(0))
	{
		signal(SIGINT, ft_sigint);
		signal(SIGQUIT, SIG_IGN);
		line = readline(promt);
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
