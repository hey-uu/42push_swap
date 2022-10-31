/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:14:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:14:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../../data_structure/push_swap_set/push_swap_set.h"

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

typedef int	(*t_cmd)(t_ps_set *);

// implement mutiple commands at once
void	implement_commands(t_ps_set *set, const int *command, int cmd_size);
void	push_all(t_ps_set *set, int cmd);
void	push_n_elements(t_ps_set *set, int number, int cmd);

// basic commands for push swap
int		sa(t_ps_set *set);
int		sb(t_ps_set *set);
int		ss(t_ps_set *set);
int		pa(t_ps_set *set);
int		pb(t_ps_set *set);
int		ra(t_ps_set *set);
int		rb(t_ps_set *set);
int		rr(t_ps_set *set);
int		rra(t_ps_set *set);
int		rrb(t_ps_set *set);
int		rrr(t_ps_set *set);

#endif