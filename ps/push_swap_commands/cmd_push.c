/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 21:27:31 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ds/ds_dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "push_swap_command.h"

void	pa(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 0)
		return ;
	popped = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_a, popped);
	dq_push_rear(set->commands, PA);
}

void	pb(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 0)
		return ;
	popped = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_b, popped);
	dq_push_rear(set->commands, PB);
}
