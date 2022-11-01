/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:38:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:43:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue_bonus.h"
#include "push_swap_set_bonus.h"
#include "command_bonus.h"

int	pa(t_ps_set *set)
{
	int	popped;

	if (set->stack_b->used_size == 0)
		return (0);
	popped = dq_pop_front(set->stack_b);
	dq_push_front(set->stack_a, popped);
	return (1);
}

int	pb(t_ps_set *set)
{
	int	popped;

	if (set->stack_a->used_size == 0)
		return (0);
	popped = dq_pop_front(set->stack_a);
	dq_push_front(set->stack_b, popped);
	return (1);
}
