/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:05:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 10:38:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static void	stacks_get_front_rear(t_ps_set *set, int *data, int cmd);

int	get_idx_highest_priority(t_ps_set *set, int *src, int mold, int cmd)
{
	int	data[3];
	int	i;
	int	highest;

	stacks_get_front_rear(set, data, cmd);
	i = -1;
	while (++i < 3)
		if (src[i] > 0)
			break ;
	highest = i;
	if (i < 2 && src[i + 1] > 0 && cmp2(data[highest], data[i + 1], mold) == BA)
		highest = i + 1;
	if (i < 1 && src[i + 2] > 0 && cmp2(data[highest], data[i + 2], mold) == BA)
		highest = i + 2;
	return (highest);
}

void	stacks_get_front_rear(t_ps_set *set, int *data, int cmd)
{
	if (cmd == PA)
	{
		data[0] = (int) dq_get_value(set->stack_a, REAR, 0);
		data[1] = (int) dq_get_value(set->stack_b, FRONT, 0);
		data[2] = (int) dq_get_value(set->stack_b, REAR, 0);
	}
	else
	{
		data[0] = (int) dq_get_value(set->stack_b, REAR, 0);
		data[1] = (int) dq_get_value(set->stack_a, FRONT, 0);
		data[2] = (int) dq_get_value(set->stack_a, REAR, 0);
	}
}
