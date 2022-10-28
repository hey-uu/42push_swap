/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 10:13:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static void	get_source(t_ps_set *set, int *arr, int s_idx, int idx);

void	merge_sorted_triangles(t_ps_set *set, int start, int cnt, int cmd)
{
	int	i;
	int	src[3];

	i = -1;
	while (++i < cnt)
	{
		get_source(set, src, start, i);
		combine_source(set, src, set->map->mold[start + i], cmd);
	}
}

void	get_source(t_ps_set *set, int *arr, int start, int idx)
{
	const int	size = 2 * start + 1;

	arr[0] = set->map->val[start + idx];
	arr[1] = set->map->val[start - 1 + 2 * (size / 3) - idx];
	arr[2] = set->map->val[start - 1 + size - idx];
}

void	combine_source(t_ps_set *set, int *src, int mold, int cmd)
{
	const int	cmd_tab[2][3][2] = {{{RRA, NON}, {PA, NON}, {RRB, PA}}, \
									{{RRB, NON}, {PB, NON}, {RRA, PB}}};
	int			highest_idx;

	while (src[0] || src[1] || src[2])
	{
		if ((cmd == PA && set->stack_b->used_size == 1) || \
			(cmd == PB && set->stack_a->used_size == 1))
		{
			src[1] = 1;
			src[2] = 0;
		}
		highest_idx = get_idx_highest_priority(set, src, mold, cmd);
		implement_commands(set, cmd_tab[cmd][highest_idx], 2);
		src[highest_idx]--;
	}
}
