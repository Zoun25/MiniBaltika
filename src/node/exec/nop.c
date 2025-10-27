/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:09:33 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/27 05:22:38 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node/exec.h"

int	node_exec_nop(t_shinf *sh, t_node __attribute__((unused))*node)
{
	return (sh->status_code);
}
