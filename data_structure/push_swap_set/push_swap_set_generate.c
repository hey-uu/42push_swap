/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_generate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:45:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 22:09:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_set.h"
#include <stdlib.h>

t_ps_set	*ps_set_create(t_dequeue *input)
{
	t_ps_set	*set;

	set = malloc(sizeof(t_ps_set));
	if (!set)
		ft_exit("Error\n", 1);
	set->map = trg_map_create(input->used_size);
	set->stack_a = dq_duplicate(input);
	set->stack_b = dq_create_dequeue(input->used_size);
	set->commands = dq_create_dequeue(input->used_size * 5);
	if (!set->map || !set->stack_a || !set->stack_b || !set->commands)
		ft_exit("Error\n", 1);
	return (set);
}

void	ps_set_destroy(t_ps_set *set)
{
	if (!set)
		return ;
	trg_map_destroy(set->map);
	dq_destroy_dequeue(set->stack_a);
	dq_destroy_dequeue(set->stack_b);
	dq_destroy_dequeue(set->commands);
	free(set);
}
