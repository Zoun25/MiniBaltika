/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:06:05 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 09:57:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"
#include "env.h"

#include "my_printf.h"
#include "basic.h"

#include <string.h>
#include <errno.h>
#include <time.h>

static int	change_dir(t_shinf *s, char *path)
{
	int		code;
	char	*error;

	code = chdir(path);
	if (code == 0)
	{
		getcwd(s->work_dir, MAX_PATH_LEN);
		return (0);
	}
	error = strerror(errno);
	my_dprintf(2, "%s: %s.\n", path, error);
	return (1);
}

int	mini_cd(t_shinf *sh, t_node_proc *proc)
{
	t_env_var	*home;

	if (proc->argc > 2)
		return (1);
	if (proc->argc == 1)
	{
		home = get_env_var(sh, "HOME");
		if (home == NULL)
			return (change_dir(sh, "/home"));
		return (change_dir(sh, home->value));
	}
	else
		return (change_dir(sh, proc->argv[1]));
}
