/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:06:05 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 10:01:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/funcs.h"
#include "env.h"

#include "basic.h"

int	mini_unset(t_shinf *sh, t_node_proc *proc)
{
	size_t	i;

	free_string_array(sh->env);
	i = 1;
	while (proc->argv[i])
	{
		remove_env_var(sh, proc->argv[i]);
		i ++;
	}
	sh->env = (char **)list_export(&sh->list_env,
			(void *(*)(void *)) & assemble_env_var);
	return (0);
}
