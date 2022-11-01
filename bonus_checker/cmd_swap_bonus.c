/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:38:30 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:31:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue_bonus.h"
#include "push_swap_set_bonus.h"
#include "command_bonus.h"

int	sa(t_ps_set *set)
{
	int	top_data;
	int	below_top_data;

	if (set->stack_a->used_size == 1)
		return (0);
	top_data = dq_pop_front(set->stack_a);
	below_top_data = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_a, top_data);
	dq_push_front(set->stack_a, below_top_data);
	return (1);
}

int	sb(t_ps_set *set)
{
	int	top_data;
	int	below_top_data;

	if (set->stack_b->used_size == 1)
		return (0);
	top_data = dq_pop_front(set->stack_b);
	below_top_data = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_b, top_data);
	dq_push_front(set->stack_b, below_top_data);
	return (1);
}

int	ss(t_ps_set *set)
{
	int	top_data;
	int	below_top_data;

	if (set->stack_a->used_size == 1 || \
		set->stack_a->used_size == 1)
		return (0);
	top_data = dq_pop_front(set->stack_a);
	below_top_data = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_a, top_data);
	dq_push_front(set->stack_a, below_top_data);
	top_data = dq_pop_front(set->stack_b);
	below_top_data = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_b, top_data);
	dq_push_front(set->stack_b, below_top_data);
	return (1);
}
