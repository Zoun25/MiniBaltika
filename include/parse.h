/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:54:00 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 16:16:43 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mini.h"
# include "node.h"

int		apply_vars(t_shinf *sh, char **line);
bool	ft_is_sq(char *line, int pos);

t_node	*parse_line(t_shinf *sh, char *line);
t_node	*parse_block(t_shinf *sh, char *line, size_t begin, size_t end);
t_node	*parse_proc(t_shinf *sh, char *line);

void	avoid_quotes(char *line, int *i, size_t begin, size_t end);

#endif // !PARSE_H
