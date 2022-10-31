/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:12:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../data_structure/dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "command.h"

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
	dq_push_rear(set->commands, SA);
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
	dq_push_rear(set->commands, SB);
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
	dq_push_rear(set->commands, SS);
	return (1);
}
