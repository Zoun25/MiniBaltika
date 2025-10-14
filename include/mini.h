/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:58:54 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/14 21:20:43 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>

typedef struct shell_information
{
	char	**env;
	int		status_code;
}	t_shinf;

struct s_pipe
{
	int	read;
	int	write;
};

void	end(t_shinf *sh);

#endif
