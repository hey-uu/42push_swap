/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:12:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../data_structure/dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "command.h"

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
