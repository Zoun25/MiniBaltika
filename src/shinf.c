/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:10:28 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 13:25:48 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

#include "basic.h"
#include "env.h"

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
		{
			shinf_destroy(sh);
			return (NULL);
		}
		if (!list_append(&sh->list_env, var))
			destroy_env_var(var);
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
	free(sh);
}
