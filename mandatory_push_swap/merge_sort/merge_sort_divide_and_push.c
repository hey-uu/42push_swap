/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_divide_and_push.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:24:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

// static void	sort_each_two_front_elements_and_rb(t_ps_set *set, int mold);

void	push_two_elements(t_ps_set *set, int mold)
{
	const int	cmd_table[2][3] = {{PB, PB, NN}, {SA, PB, PB}};
	int			front[2];
	int			cmd;

	dq_get_values(set->stack_a, front, FRONT, 2);
	cmd = cmp2(front[0], front[1], mold);
	implement_commands(set, cmd_table[cmd], 3);
}

void	push_three_elements(t_ps_set *set, int mold)
{
	const int	tab[9][5] = {{PB, PB, PB, NN, NN}, {SA, PB, PB, PB, NN}, \
						{RA, PB, PB, PB, NN}, {PB, PB, RRA, PB, NN}, \
						{PB, RRA, PB, PB, NN}, {RRA, PB, PB, PB, NN}, \
						{SA, PB, PB, RRA, PB}, {RRA, PB, SA, PB, PB}, \
						{SA, PB, RRA, PB, PB}};
	const int	rear = (int)dq_get_value(set->stack_a, REAR, 0);
	int			front[4];
	int			cmd;

	dq_get_values(set->stack_a, front, FRONT, 4);
	if (cmp3(front[0], front[1], front[2], mold) == ABC)
		cmd = _3_ABC;
	else if (cmp3(front[0], front[1], front[2], mold) == BAC)
		cmd = _3_BAC;
	else if (set->stack_a->used_size >= 4 && \
			cmp3(front[0], front[1], front[2], mold) == CAB && \
			cmp2(front[2], front[3], mold) == AB)
		cmd = _3_DABC;
	else
		cmd = cmp3(front[0], front[1], rear, mold) + 3;
	implement_commands(set, tab[cmd], 5);
}

void	push_four_elements(t_ps_set *set, int mold)
{
	int	src[3];

	pb(set);
	rb(set);
	if (cmp2(dq_get_value(set->stack_a, FRONT, 0), \
		dq_get_value(set->stack_a, FRONT, 1), mold) == BA)
		sa(set);
	src[0] = 1;
	src[1] = 2;
	src[2] = 1;
	combine_source(set, src, mold, PB);
}
