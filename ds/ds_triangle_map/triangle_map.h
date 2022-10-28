/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:58:09 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 13:58:10 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAP_H
# define TRIANGLE_MAP_H

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

enum e_mold_type
{
	UP = 0,
	DOWN = 1
};

typedef struct s_trg_map
{
	int			*val;
	char		*mold;
	int			size;
	int			depth;
}	t_trg_map;

// triangle_map_generate
t_trg_map	*trg_map_create(int size);
void		trg_map_destroy(t_trg_map *map);

// triangle_map_show
void		trg_map_show_1(const t_trg_map *map, int cur_depth, int idx);
void		trg_map_show_2(const t_trg_map *map);

// triangle_map_utils
int			trg_map_get_level_start_idx(int depth);
#endif