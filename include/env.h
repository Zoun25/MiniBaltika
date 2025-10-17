/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:58:20 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 05:31:51 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stddef.h>

# include "mini.h"

typedef struct environment_variable
{
	char	*name;
	char	*value;
	size_t	total_len;
}	t_env_var;

int			update_path(t_shinf *sh, char *path);

t_env_var	*create_env_var(char *raw);
char		*assemble_env_var(t_env_var *v);
void		destroy_env_var(t_env_var *v);

t_env_var	*env_var_from_parts(char *name, char *value);
t_env_var	*get_env_var(t_shinf *s, char *name);
int			remove_env_var(t_shinf *s, char *name);
int			set_env_var(t_shinf *s, char *name, char *value);
ssize_t		get_env_index(t_shinf *s, char *name);

#endif
