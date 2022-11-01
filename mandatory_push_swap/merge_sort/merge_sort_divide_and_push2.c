/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_divide_and_push2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:09:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:25:32 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

void	sort_each_two_front_elements_and_rr(t_ps_set *set, int mold)
{
	const int	a[2] = {dq_get_value(set->stack_a, FRONT, 0), \
						dq_get_value(set->stack_a, FRONT, 1)};
	const int	b[2] = {dq_get_value(set->stack_b, FRONT, 0), \
						dq_get_value(set->stack_b, FRONT, 1)};
	const int	cmp_a = cmp2(a[0], a[1], mold);
	const int	cmp_b = cmp2(b[0], b[1], mold);

	if (cmp_a == AB && cmp_b == AB)
		ss(set);
	else if (cmp_a == AB && cmp_b == BA)
		sa(set);
	else if (cmp_a == BA && cmp_b == AB)
		sb(set);
	rr(set);
	rr(set);
}

void	sort_three_elements_in_place(t_ps_set *set, int mold)
{
	const int	tab[9][5] = {{NN, NN, NN, NN, NN}, {SA, NN, NN, NN, NN}, \
							{RA, NN, NN, NN, NN}, {PB, RRA, SA, PA, NN}, \
							{RRA, SA, NN, NN, NN}, {RRA, NN, NN, NN, NN}, \
							{PB, RRA, SA, PA, SA}, {SA, RRA, NN, NN, NN}, \
							{SA, RRA, SA, NN, NN}};
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

void	push_five_elements(t_ps_set *set, int mold)
{
	int	src[3];

	pb(set);
	rb(set);
	sort_three_elements_in_place(set, mold);
	src[0] = 1;
	src[1] = 3;
	src[2] = 1;
	combine_source(set, src, mold, PB);
}

void	push_six_elements(t_ps_set *set, int mold)
{
	int	src[3];

	push_n_elements(set, 2, PB);
	sort_each_two_front_elements_and_rr(set, mold);
	if (cmp2(dq_get_value(set->stack_a, FRONT, 0), \
		dq_get_value(set->stack_a, FRONT, 1), mold) == BA)
		sa(set);
	src[0] = 2;
	src[1] = 2;
	src[2] = 2;
	combine_source(set, src, mold, PB);
}

void	push_seven_elements(t_ps_set *set, int mold)
{
	int	src[3];

	push_three_elements(set, mold);
	if (cmp2(dq_get_value(set->stack_a, FRONT, 0), \
		dq_get_value(set->stack_a, FRONT, 1), mold) == AB)
		sa(set);
	rr(set);
	rr(set);
	rb(set);
	if (cmp2(dq_get_value(set->stack_a, FRONT, 0), \
		dq_get_value(set->stack_a, FRONT, 1), mold) == BA)
		sa(set);
	src[0] = 3;
	src[1] = 2;
	src[2] = 2;
	combine_source(set, src, mold, PB);
}
