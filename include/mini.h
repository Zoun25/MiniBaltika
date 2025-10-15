/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:58:54 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 13:12:12 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>
# include <linked_list.h>

typedef struct shell_information
{
	t_list	list_env;
	char	**env;
	int		status_code;
}	t_shinf;

struct s_pipe
{
	int	read;
	int	write;
};

t_shinf	*shinf_create(char **env);
void	shinf_destroy(t_shinf *sh);

void	end(t_shinf *sh);

#endif
