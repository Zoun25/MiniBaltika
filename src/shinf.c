/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:10:28 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 23:56:25 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "node.h"
#include "env.h"

#include "basic.h"

t_shinf	*shinf_create(char **env)
{
	t_shinf		*sh;
	size_t		i;
	t_env_var	*var;

	sh = my_calloc(1, sizeof(t_shinf));
	if (sh == NULL)
		return (NULL);
	list_initialize(&sh->list_env, (void (*)(void *)) & destroy_env_var);
	i = 0;
	while (env[i])
	{
		var = create_env_var(env[i]);
		if (var == NULL)
			return (shinf_destroy(sh), NULL);
		if (!list_append(&sh->list_env, var))
			destroy_env_var(var);
		if (my_strcmp(var->name, "PATH") == 0)
			update_path(sh, var->value);
		i ++;
	}
	sh->env = (char **)list_export(&sh->list_env,
			(void *(*)(void *)) & assemble_env_var);
	return (sh);
}

void	shinf_destroy(t_shinf *sh)
{
	if (sh == NULL)
		return ;
	list_delete(&sh->list_env);
	free_string_array(sh->env);
	free_string_array(sh->path.path);
	node_destroy(sh->line);
	free(sh);
}
