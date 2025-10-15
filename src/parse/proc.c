/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:14:17 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/15 21:47:33 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "node_create.h"

#include "basic.h"
#include "my_printf.h"

t_node	*parse_proc(t_shinf *sh, char *line)
{
	t_node	*proc;
	char	**splited;

	(void)sh;
	splited = my_coolersplit(line, " \t");
	if (splited == NULL)
		return (NULL);
	proc = node_create_proc(get_pointer_array_len(splited), splited);
	if (proc == NULL)
		free_string_array(splited);
	return (proc);
}
