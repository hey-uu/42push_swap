/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:12:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../data_structure/dequeue/ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"
#include "command.h"

int	pa(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 0)
		return (0);
	popped = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_a, popped);
	dq_push_rear(set->commands, PA);
	return (1);
}

int	pb(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 0)
		return (0);
	popped = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_b, popped);
	dq_push_rear(set->commands, PB);
	return (1);
}
