/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:10:31 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 12:56:50 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include "basic.h"

void	destroy_env_var(t_env_var *v)
{
	if (v == NULL)
		return ;
	free(v->name);
	free(v->value);
	free(v);
}

t_env_var	*create_env_var(char *raw)
{
	t_env_var	*result;
	ssize_t		key;
	ssize_t		value;

	key = my_strchr_index(raw, '=');
	value = my_strlen(raw + key + 1);
	if (key <= 0 || value < 0)
		return (NULL);
	result = malloc(sizeof(t_env_var) * 1);
	if (result == NULL)
		return (result);
	result->name = malloc(sizeof(char) * (key + 1));
	result->value = malloc(sizeof(char) * (value + 1));
	if (result->name == NULL || result->value == NULL)
	{
		destroy_env_var(result);
		return (NULL);
	}
	my_strncpy(result->name, raw, key);
	result->name[key] = '\0';
	my_strcpy(result->value, raw + key + 1);
	result->total_len = key + value + 1;
	return (result);
}

char	*assemble_env_var(t_env_var *v)
{
	return (my_coolerstrjoin(3, v->name, "=", v->value));
}

t_env_var	*env_var_from_parts(char *name, char *value)
{
	t_env_var	*result;

	result = my_calloc(sizeof(t_env_var), 1);
	if (result == NULL)
		return (NULL);
	result->name = my_strdup(name);
	result->value = my_strdup(value);
	if (result->name == NULL || result->value == NULL)
	{
		destroy_env_var(result);
		return (NULL);
	}
	return (result);
}

int	remove_env_var(t_shinf *s, char *name)
{
	ssize_t	index;

	index = get_env_index(s, name);
	if (index < 0)
		return (0);
	return (list_pop(&s->list_env, index));
}
