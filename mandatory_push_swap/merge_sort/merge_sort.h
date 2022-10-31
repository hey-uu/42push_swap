/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:12:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H

# include "../../data_structure/dequeue/ft_dequeue.h"
# include "../../data_structure/push_swap_set/push_swap_set.h"
# include "../../data_structure/triangle_map/triangle_map.h"
# include "../../libft/ft_printf/ft_printf.h"
# include "../commands/command.h"

enum e_two_comb
{
	AB = 0,
	BA = 1,
	AA = 2
};

enum e_three_comb
{
	ABC = 0,
	ACB = 1,
	BCA = 2,
	BAC = 3,
	CBA = 4,
	CAB = 5,
	AAB = 6,
	BAA = 7,
	BBA = 8,
	ABB = 9,
	BAB = 10,
	ABA = 11,
	AAA = 12
};

enum e_three_push_cmds
{
	_3_ABC = 0,
	_3_BAC = 1,
	_3_DABC = 2,
	_3_AB_C = 3,
	_3_AC_B = 4,
	_3_BC_A = 5,
	_3_BA_C = 6,
	_3_CB_A = 7,
	_3_CA_B = 8
};

// merge_sort_compare
int		cmp2(int a, int b, int mold);
int		cmp3(int a, int b, int c, int mold);
int		get_extreme_value_idx(int	*arr, int size, int cmp);

// get_idx_highest_priority
int		get_idx_highest_priority(t_ps_set *set, int *src, int mold, int cmd);
void	combine_source(t_ps_set *set, int *src, int mold, int cmd);

// merge_sort_conquer
void	merge_sorted_triangles(t_ps_set *set, int start, int cnt, int cmd);

// merge_sort_divide_and_push1
void	push_two_elements(t_ps_set *set, int mold);
void	push_three_elements(t_ps_set *set, int mold);
void	push_four_elements(t_ps_set *set, int mold);
void	push_five_elements(t_ps_set *set, int mold);

// merge_sort.c
void	ps_merge_sort(t_ps_set *set);

#endif