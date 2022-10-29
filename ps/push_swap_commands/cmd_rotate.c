/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 13:15:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ds/ds_dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "push_swap_command.h"

int	ra(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
		return (1);
	popped = dq_pop_front(set->stack_a);
	dq_push_rear(set->stack_a, popped);
	dq_push_rear(set->commands, RA);
	return (1);
}

int	rb(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 1)
		return (1);
	popped = dq_pop_front(set->stack_b);
	dq_push_rear(set->stack_b, popped);
	dq_push_rear(set->commands, RB);
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
	dq_push_rear(set->commands, RR);
	return (1);
}
