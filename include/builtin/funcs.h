/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:33:00 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/18 09:24:13 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "builtin/list.h"
# include "mini.h"
# include "node.h"

int	mini_echo(t_shinf *sh, t_node_proc *proc);
int	mini_cd(t_shinf *sh, t_node_proc *proc);
int	mini_pwd(t_shinf *sh, t_node_proc *proc);
int	mini_export(t_shinf *sh, t_node_proc *proc);
int	mini_unset(t_shinf *sh, t_node_proc *proc);
int	mini_env(t_shinf *sh, t_node_proc *proc);
int	mini_exit(t_shinf *sh, t_node_proc *proc);

int	mini_builtin(t_shinf *sh, t_node_proc *proc);

int	get_write_fd(t_node_block *block, size_t id);

#endif
