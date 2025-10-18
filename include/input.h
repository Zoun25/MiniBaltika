/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 03:44:43 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 02:27:44 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "mini.h"
# include "node.h"

# include <stdbool.h>

typedef enum redirections
{
	NON = 0b000,
	SINGLE_INPUT = 0b100,
	DUAL_INPUT = 0b110,
	SINGLE_OUTPUT = 0b101,
	DUAL_OUTPUT = 0b111,
	DUAL = 0b010,
	OUTPUT = 0b001,
}	t_redir;

char			*mini_line(bool print);
int				open_redir(t_redir redir, char *arg);
void			close_pipe(struct s_pipe *pipe);
t_executable	get_executable(t_shinf *sh, char *command);
void			manage_children(t_node_block *block);

#endif
