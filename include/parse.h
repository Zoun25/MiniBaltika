/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:54:00 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 06:25:16 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mini.h"
# include "node.h"

int		apply_vars(t_shinf *sh, char **line);
t_node	*parse_line(t_shinf *sh, char *line);
t_node	*parse_block(t_shinf *sh, char *line, size_t begin, size_t end);

#endif // !PARSE_H
