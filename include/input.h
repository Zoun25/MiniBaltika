/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 03:44:43 by angsanch          #+#    #+#             */
/*   Updated: 2026/05/12 21:37:26 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "mini.h"
# include "node.h"
# include "token/token.h"

# include <stdbool.h>

void			executor_signals(void);
void			child_signals(void);

char			*mini_line(t_shinf *sh, bool print);
int				open_redir(t_redir redir, char *arg);
void			close_pipe(struct s_pipe *pipe);
t_executable	get_executable(t_shinf *sh, char *command);
void			manage_children(t_shinf *sh, t_node_block *block);

#endif
