/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:58:54 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 01:22:47 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>
# include <linked_list.h>

# include "builtin/list.h"

typedef struct node	t_node;

typedef struct path
{
	char	**path;
	size_t	longest;
}	t_path;

typedef struct shell_information
{
	t_list	list_env;
	char	**env;
	int		status_code;
	t_path	path;
	t_node	*line;
	t_node	*block;
}	t_shinf;

struct s_pipe
{
	int	read;
	int	write;
};

typedef struct executable
{
	char			*bin;
	t_builtin_id	builtin;
}	t_executable;

t_shinf	*shinf_create(char **env);
void	shinf_destroy(t_shinf *sh);

void	end(t_shinf *sh);

#endif
