/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 02:30:59 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/17 03:13:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	close_pipe(struct s_pipe *pipe)
{
	if (pipe->read >= 0)
		close(pipe->read);
	if (pipe->write >= 0)
		close(pipe->write);
}
