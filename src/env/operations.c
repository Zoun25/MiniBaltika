/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:14:31 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 05:02:17 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include "basic.h"
#include "linked_list.h"

static int	env_check_key(void *haystack, void *needle)
{
	return (my_strcmp(((t_env_var *)haystack)->name, needle) == 0);
}

ssize_t	get_env_index(t_shinf *s, char *name)
{
	return (list_first_fulfil(&s->list_env, &env_check_key, name));
}

t_env_var	*get_env_var(t_shinf *s, char *name)
{
	ssize_t	index;

	index = get_env_index(s, name);
	if (index < 0)
		return (NULL);
	return (list_get_index(&s->list_env, index));
}

static int	check_variable_name(char *name)
{
	size_t	i;

	i = 0;
	if (name == NULL)
		return (0);
	if (!my_isalpha(name[0]))
		return (0);
	while (name[i] != '\0')
	{
		if (!(my_isalpha(name[i]) || my_isnumeric(name[i]) || name[i] == '_'))
			return (0);
		i ++;
	}
	return (1);
}

int	set_env_var(t_shinf *s, char *name, char *value)
{
	t_env_var	*temp;
	ssize_t		index;
	int			status;

	index = get_env_index(s, name);
	if (!check_variable_name(name))
		return (0);
	temp = env_var_from_parts(name, value);
	if (temp == NULL)
		return (0);
	if (my_strcmp(temp->name, "PATH") == 0)
		if (!update_path(s, temp->value))
			return (destroy_env_var(temp), 0);
	if (index < 0)
		status = list_append(&s->list_env, temp);
	else
	{
		list_pop(&s->list_env, index);
		status = list_insert(&s->list_env, index, temp);
	}
	if (status)
		return (1);
	destroy_env_var(temp);
	return (0);
}
