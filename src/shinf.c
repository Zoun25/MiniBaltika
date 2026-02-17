/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:10:28 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 10:11:52 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "node.h"
#include "env.h"

#include "basic.h"
#include "my_printf.h"

static bool	update_shlvl(t_shinf *sh)
{
	t_env_var	*var;
	char		*tmp;

	tmp = NULL;
	var = get_env_var(sh, "SHLVL");
	if (var == NULL)
	{
		if (!set_env_var(sh, "SHLVL", "1"))
			return (false);
	}
	else
	{
		if (my_sbufferf(&tmp, "%d", my_getnbr(var->value) + 1) < 0)
			return (false);
		if (!set_env_var(sh, "SHLVL", tmp))
		{
			free(tmp);
			return (false);
		}
		free(tmp);
	}
	return (true);
}

static t_shinf	*shinf_env(t_shinf *sh, char **env)
{
	size_t		i;
	t_env_var	*var;

	list_initialize(&sh->list_env, (void (*)(void *)) & destroy_env_var);
	i = 0;
	while (env[i])
	{
		var = create_env_var(env[i]);
		if (var == NULL)
			return (shinf_destroy(sh), NULL);
		if (!list_append(&sh->list_env, var))
			destroy_env_var(var);
		i ++;
	}
	var = get_env_var(sh, "PATH");
	if (var != NULL)
		update_path(sh, var->value);
	if (update_shlvl(sh) == false)
		return (shinf_destroy(sh), NULL);
	sh->env = (char **)list_export(&sh->list_env,
			(void *(*)(void *)) & assemble_env_var);
	return (sh);
}

t_shinf	*shinf_create(char **env)
{
	t_shinf		*sh;

	sh = my_calloc(1, sizeof(t_shinf));
	if (sh == NULL)
		return (NULL);
	getcwd(sh->work_dir, MAX_PATH_LEN);
	return (shinf_env(sh, env));
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
