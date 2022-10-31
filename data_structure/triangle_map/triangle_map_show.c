/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 13:58:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle_map.h"
#include "../../libft/ft_printf/ft_printf.h"

void	trg_map_show_1(const t_trg_map *map, int cur_depth, int idx)
{
	int	i;

	if (cur_depth > map->depth)
		return ;
	i = -1;
	while (++i < cur_depth)
		ft_printf("    ");
	if (cur_depth > 0)
		ft_printf("+--");
	if (map->mold[idx] == UP)
		ft_printf("%d(%dU)\n", map->val[idx], cur_depth);
	else
		ft_printf("%d(%dD)\n", map->val[idx], cur_depth);
	trg_map_show_1(map, cur_depth + 1, 3 * idx + 1);
	trg_map_show_1(map, cur_depth + 1, 3 * idx + 2);
	trg_map_show_1(map, cur_depth + 1, 3 * idx + 3);
}

void	trg_map_show_2(const t_trg_map *map)
{
	const int	start = trg_map_get_level_start_idx(map->depth);
	const int	size = 2 * start + 1;
	int			i;

	i = -1;
	while (++i < size)
	{
		if (map->mold[start + i] == UP)
			ft_printf("%d(%dU)\n", map->val[start + i], map->depth);
		else
			ft_printf("%d(%dD)\n", map->val[start + i], map->depth);
	}
}
