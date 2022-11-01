/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:52:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../data_structure/dequeue/dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "command.h"

int	rra(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
		return (0);
	popped = dq_pop_rear(set->stack_a);
	dq_push_front(set->stack_a, popped);
	dq_push_rear(set->commands, RRA);
	return (1);
}

int	rrb(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 1)
		return (0);
	popped = dq_pop_rear(set->stack_b);
	dq_push_front(set->stack_b, popped);
	dq_push_rear(set->commands, RRB);
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
	dq_push_rear(set->commands, RRR);
	return (1);
}
