/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 21:27:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ds/ds_dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "push_swap_command.h"

void	rra(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
		return ;
	popped = dq_pop_rear(set->stack_a);
	dq_push_front(set->stack_a, popped);
	dq_push_rear(set->commands, RRA);
}

void	rrb(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 1)
		return ;
	popped = dq_pop_rear(set->stack_b);
	dq_push_front(set->stack_b, popped);
	dq_push_rear(set->commands, RRB);
}

void	rrr(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 1)
	{
		rra(set);
		return ;
	}
	if (set->stack_b->used_size == 1)
	{
		rrb(set);
		return ;
	}
	popped = dq_pop_rear(set->stack_a);
	dq_push_front(set->stack_a, popped);
	popped = dq_pop_rear(set->stack_b);
	dq_push_front(set->stack_b, popped);
	dq_push_rear(set->commands, RRR);
}
