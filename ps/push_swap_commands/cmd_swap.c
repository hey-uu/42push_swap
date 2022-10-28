/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 21:27:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ds/ds_dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "push_swap_command.h"

void	sa(t_ps_set *set)
{
	int	top_data;
	int	below_top_data;

	if (set->stack_a->used_size == 1)
		return ;
	top_data = dq_pop_front(set->stack_a);
	below_top_data = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_a, top_data);
	dq_push_front(set->stack_a, below_top_data);
	dq_push_rear(set->commands, SA);
}

void	sb(t_ps_set *set)
{
	int	top_data;
	int	below_top_data;

	if (set->stack_b->used_size == 1)
		return ;
	top_data = dq_pop_front(set->stack_b);
	below_top_data = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_b, top_data);
	dq_push_front(set->stack_b, below_top_data);
	dq_push_rear(set->commands, SB);
}

void	ss(t_ps_set *set)
{
	int	top_data;
	int	below_top_data;

	if (set->stack_a->used_size == 1)
	{
		sb(set);
		return ;
	}
	if (set->stack_b->used_size == 1)
	{
		sa(set);
		return ;
	}
	top_data = dq_pop_front(set->stack_a);
	below_top_data = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_a, top_data);
	dq_push_front(set->stack_a, below_top_data);
	top_data = dq_pop_front(set->stack_b);
	below_top_data = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_b, top_data);
	dq_push_front(set->stack_b, below_top_data);
	dq_push_rear(set->commands, SS);
}
