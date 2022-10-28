/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 16:25:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMAND_H
# define PUSH_SWAP_COMMAND_H

# include "../../ds/ds_push_swap_set/push_swap_set.h"

enum e_cmd
{
	PA = 0,
	PB = 1,
	SA = 2,
	SB = 3,
	SS = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10,
	NON = 11
};

typedef void	(*t_cmd)(t_ps_set *);

// implement mutiple commands at once
void	implement_commands(t_ps_set *set, const int *command, int cmd_size);
void	push_all(t_ps_set *set, int cmd);
void	push_n_elements(t_ps_set *set, int number, int cmd);

// basic commands for push swap
void	sa(t_ps_set *set);
void	sb(t_ps_set *set);
void	ss(t_ps_set *set);
void	pa(t_ps_set *set);
void	pb(t_ps_set *set);
void	ra(t_ps_set *set);
void	rb(t_ps_set *set);
void	rr(t_ps_set *set);
void	rra(t_ps_set *set);
void	rrb(t_ps_set *set);
void	rrr(t_ps_set *set);

#endif