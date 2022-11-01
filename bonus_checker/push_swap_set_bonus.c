/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_generate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:45:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:11:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_set_bonus.h"
#include "../libft/ft_libft_mandatory/libft.h"
#include <stdlib.h>

t_ps_set	*ps_set_create(t_dequeue *input)
{
	t_ps_set	*set;

	set = malloc(sizeof(t_ps_set));
	if (!set)
		ft_exit("Error\n", 1);
	set->stack_a = dq_duplicate(input);
	set->stack_b = dq_create_dequeue(input->used_size);
	return (set);
}
