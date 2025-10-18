/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 04:34:17 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 11:18:22 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

#include "basic.h"
#include "my_printf.h"

static char	*get_path(t_path *path, char *name)
{
	char	*result;
	size_t	i;

	if (path->path == NULL)
		return (NULL);
	if (my_strchr_count(name, '/') > 0)
		return (my_strdup(name));
	result = malloc((path->longest + my_strlen(name) + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (path->path[i])
	{
		my_strcpy(result, path->path[i]);
		if (result[my_strlen(result) - 1] != '/')
			my_strcat(result, "/");
		my_strcat(result, name);
		if (access(result, R_OK | X_OK) == 0)
			return (result);
		i ++;
	}
	my_dprintf(2, "Error 127: command not found: %s\n", result);
	free(result);
	return (NULL);
}

static t_builtin_id	get_builtin(char *command)
{
	if (my_strcmp(command, "echo") == 0)
		return (ECHO);
	else if (my_strcmp(command, "cd") == 0)
		return (CD);
	else if (my_strcmp(command, "pwd") == 0)
		return (PWD);
	else if (my_strcmp(command, "export") == 0)
		return (EXPORT);
	else if (my_strcmp(command, "unset") == 0)
		return (UNSET);
	else if (my_strcmp(command, "env") == 0)
		return (ENV);
	else if (my_strcmp(command, "exit") == 0)
		return (EXIT);
	return (NONE);
}

t_executable	get_executable(t_shinf *sh, char *command)
{
	t_executable	exec;

	exec.bin = NULL;
	exec.builtin = get_builtin(command);
	if (exec.builtin != NONE)
		return (exec);
	exec.bin = get_path(&sh->path, command);
	return (exec);
}
