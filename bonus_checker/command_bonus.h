/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:33:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:12:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_BONUS_H
# define COMMAND_BONUS_H

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
	NN = 11
};

typedef int	(*t_cmd)(t_ps_set *);

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