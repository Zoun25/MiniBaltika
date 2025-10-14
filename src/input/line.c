/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 04:12:16 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/14 04:16:37 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "basic.h"
#include "my_printf.h"

char	*mini_line(void)
{
	if (isatty(0))
	{
		my_printf("%s ", ">");
		return (get_next_line(0));
	} else {
		return (get_next_line(0));
	}
}
