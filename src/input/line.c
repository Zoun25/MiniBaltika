/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 04:12:16 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/14 23:43:42 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "basic.h"
#include "my_printf.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

static void	ft_sigint(int __attribute((unused))signum)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*mini_line(void)
{
	char	*line;

	if (isatty(0))
	{
		signal(SIGINT, ft_sigint);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		line = readline("baltika$ ");
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
