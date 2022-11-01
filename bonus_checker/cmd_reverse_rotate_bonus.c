/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:38:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:43:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue_bonus.h"
#include "push_swap_set_bonus.h"
#include "command_bonus.h"

int	rra(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
		return (0);
	popped = dq_pop_rear(set->stack_a);
	dq_push_front(set->stack_a, popped);
	return (1);
}

int	rrb(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 1)
		return (0);
	popped = dq_pop_rear(set->stack_b);
	dq_push_front(set->stack_b, popped);
	return (1);
}

int	rrr(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
	{
		rra(set);
		return (1);
	}
	if (set->stack_b->used_size == 1)
	{
		rrb(set);
		return (1);
	}
	popped = dq_pop_rear(set->stack_a);
	dq_push_front(set->stack_a, popped);
	popped = dq_pop_rear(set->stack_b);
	dq_push_front(set->stack_b, popped);
	return (1);
}
