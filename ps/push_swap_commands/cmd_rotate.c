/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 21:27:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ds/ds_dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "push_swap_command.h"

void	ra(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
		return ;
	popped = dq_pop_front(set->stack_a);
	dq_push_rear(set->stack_a, popped);
	dq_push_rear(set->commands, RA);
}

void	rb(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 1)
		return ;
	popped = dq_pop_front(set->stack_b);
	dq_push_rear(set->stack_b, popped);
	dq_push_rear(set->commands, RB);
}

void	rr(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
	{
		rb(set);
		return ;
	}
	popped = dq_pop_front(set->stack_a);
	dq_push_rear(set->stack_a, popped);
	if (set->stack_b->used_size == 1)
	{
		ra(set);
		return ;
	}
	popped = dq_pop_front(set->stack_b);
	dq_push_rear(set->stack_b, popped);
	dq_push_rear(set->commands, RR);
}
