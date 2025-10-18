/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:06:05 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 10:27:12 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"
#include "env.h"

#include "basic.h"
#include "my_printf.h"

#include <string.h>
#include <errno.h>

int	mini_export(t_shinf *sh, t_node_proc *proc)
{
	char	*error;
	char	**parts;

	if (proc->argc == 1)
		mini_env(sh, proc);
	if (proc->argc != 2)
		return (1);
	parts = my_split(proc->argv[1], '=');
	if (get_pointer_array_len(parts) > 2)
		return (free_string_array(parts), 1);
	if (!set_env_var(sh, parts[0], parts[1]))
	{
		if (errno)
			error = strerror(errno);
		else
			error = "Variable name must contain alphanumeric characters";
		my_dprintf(2, "%s: %s.\n", proc->argv[0], error);
		free_string_array(parts);
		return (1);
	}
	free_string_array(sh->env);
	sh->env = (char **)list_export(&sh->list_env,
			(void *(*)(void *)) & assemble_env_var);
	free_string_array(parts);
	return (0);
}
