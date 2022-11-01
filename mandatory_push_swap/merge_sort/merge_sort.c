/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:56 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:19:11 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static void	divide_to_triangles_and_pb(t_ps_set *set);
static void	merge_triangles_for_all_levels(t_ps_set *set);
static void	push_one_third(t_ps_set *set, int e_idx, int size, int depth);

void	ps_merge_sort(t_ps_set *set)
{
	divide_to_triangles_and_pb(set);
	merge_triangles_for_all_levels(set);
	if (!(set->map->depth % 2))
		push_all(set, PA);
}

void	divide_to_triangles_and_pb(t_ps_set *set)
{
	const int	start = trg_map_get_level_start_idx(set->map->depth);
	const int	level_size = 2 * start + 1;
	int			i;

	i = -1;
	while (++i < level_size)
	{
		if (set->map->val[start + i] == 1)
			pb(set);
		else if (set->map->val[start + i] == 2)
			push_two_elements(set, set->map->mold[start + i]);
		else if (set->map->val[start + i] == 3)
			push_three_elements(set, set->map->mold[start + i]);
		else if (set->map->val[start + i] == 4)
			push_four_elements(set, set->map->mold[start + i]);
		else if (set->map->val[start + i] == 5)
			push_five_elements(set, set->map->mold[start + i]);
		else if (set->map->val[start + i] == 6)
			push_six_elements(set, set->map->mold[start + i]);
		else if (set->map->val[start + i] == 7)
			push_seven_elements(set, set->map->mold[start + i]);
	}
}

void	merge_triangles_for_all_levels(t_ps_set *set)
{
	int	start;
	int	level_size;
	int	cnt;

	start = trg_map_get_level_start_idx(set->map->depth);
	level_size = 2 * start + 1;
	cnt = -1;
	while (++cnt < set->map->depth)
	{
		level_size /= 3;
		push_one_third(set, start, level_size, cnt);
		if (cnt % 2 == 0)
			merge_sorted_triangles(set, start, level_size, PA);
		else
			merge_sorted_triangles(set, start, level_size, PB);
		start = (level_size - 1) / 2;
	}
}

void	push_one_third(t_ps_set *set, int start, int size, int cnt)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (++i < size)
		n += set->map->val[start + i];
	if (cnt % 2 == 0)
		push_n_elements(set, n, PA);
	else
		push_n_elements(set, n, PB);
}
