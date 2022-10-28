/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_exceptional_cases.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:35:57 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 09:31:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ds/ds_push_swap_set/push_swap_set.h"
#include "../ds/ds_dequeue/ft_dequeue.h"
#include "push_swap_merge_sort/merge_sort.h"

static void	sort_two_input_values(t_ps_set *set);
static void	sort_three_input_values(t_ps_set *set);
static void	sort_four_input_values(t_ps_set *set);
static void	sort_five_input_values(t_ps_set *set);

void	ps_sort_exceptional_cases(t_ps_set *set)
{
	if (set->stack_a->used_size == 2)
		sort_two_input_values(set);
	else if (set->stack_a->used_size == 3)
		sort_three_input_values(set);
	else if (set->stack_a->used_size == 4)
		sort_four_input_values(set);
	else if (set->stack_a->used_size == 5)
		sort_five_input_values(set);
}

void	sort_two_input_values(t_ps_set *set)
{
	if (dq_get_value(set->stack_a, FRONT, 0) > \
		dq_get_value(set->stack_a, FRONT, 1))
		sa(set);
}

void	sort_three_input_values(t_ps_set *set)
{
	const int	cmp_res = cmp3(dq_get_value(set->stack_a, FRONT, 0), \
							dq_get_value(set->stack_a, FRONT, 1), \
							dq_get_value(set->stack_a, FRONT, 2), UP);
	const int	tab[6][2] = {{SA, RRA}, {RA, NON}, {SA, NON}, \
							{RRA, NON}, {NON, NON}, {SA, RA}};

	implement_commands(set, tab[cmp_res], 2);
}

void	sort_four_input_values(t_ps_set *set)
{
	const int	pb_tab[4][3] = {{PB, NON, NON}, {RA, PB, NON}, \
								{RA, RA, PB}, {RRA, PB, NON}};
	int			values[4];
	int			min_idx;

	dq_get_values(set->stack_a, values, FRONT, 4);
	min_idx = get_extreme_value_idx(values, 4, DOWN);
	implement_commands(set, pb_tab[min_idx], 3);
	sort_three_input_values(set);
	pa(set);
}

void	sort_five_input_values(t_ps_set *set)
{
	const int	pb_tab[5][3] = {{PB, NON, NON}, {RA, PB, NON}, {RA, RA, PB}, \
								{RRA, RRA, PB}, {RRA, PB, NON}};
	int			values[5];
	int			min_idx;

	dq_get_values(set->stack_a, values, FRONT, 5);
	min_idx = get_extreme_value_idx(values, 5, DOWN);
	implement_commands(set, pb_tab[min_idx], 3);
	sort_four_input_values(set);
	pa(set);
}
