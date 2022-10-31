/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map_get_idx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 13:57:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	trg_map_get_level_start_idx(int depth)
{
	int	i;
	int	start_idx;

	i = -1;
	start_idx = 0;
	while (++i < depth)
		start_idx = 3 * start_idx + 1;
	return (start_idx);
}
