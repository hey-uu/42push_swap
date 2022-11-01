/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:38:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:31:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue_bonus.h"
#include "push_swap_set_bonus.h"
#include "command_bonus.h"

int	ra(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
		return (1);
	popped = dq_pop_front(set->stack_a);
	dq_push_rear(set->stack_a, popped);
	return (1);
}

int	rb(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 1)
		return (1);
	popped = dq_pop_front(set->stack_b);
	dq_push_rear(set->stack_b, popped);
	return (1);
}

int	rr(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
	{
		rb(set);
		return (1);
	}
	popped = dq_pop_front(set->stack_a);
	dq_push_rear(set->stack_a, popped);
	if (set->stack_b->used_size == 1)
	{
		ra(set);
		return (1);
	}
	popped = dq_pop_front(set->stack_b);
	dq_push_rear(set->stack_b, popped);
	return (1);
}
