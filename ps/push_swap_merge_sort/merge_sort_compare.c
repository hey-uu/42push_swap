/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_compare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:49:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 09:10:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static int	cmp3_case_ab(const int res[]);
static int	cmp3_case_ba(const int res[]);

int	cmp2(int a, int b, int mold)
{
	if (a - b == 0)
		return (AA);
	if (mold == UP)
	{
		if (a - b > 0)
			return (AB);
		else
			return (BA);
	}
	else
	{
		if (b - a > 0)
			return (AB);
		else
			return (BA);
	}
}

int	cmp3(int a, int b, int c, int mold)
{
	const int	res[3] = {cmp2(a, b, mold), cmp2(b, c, mold), cmp2(a, c, mold)};

	if (res[0] == AB)
		return (cmp3_case_ab(res));
	if (res[0] == BA)
		return (cmp3_case_ba(res));
	if (res[1] == AB)
		return (AAB);
	if (res[1] == BA)
		return (BBA);
	return (AAA);
}

int	cmp3_case_ab(const int res[])
{
	if (res[1] == AB)
		return (ABC);
	if (res[1] == AA)
		return (ABB);
	if (res[2] == AB)
		return (ACB);
	if (res[2] == AA)
		return (ABA);
	return (BCA);
}

int	cmp3_case_ba(const int res[])
{
	if (res[1] == BA)
		return (CBA);
	if (res[1] == AA)
		return (BAA);
	if (res[2] == AB)
		return (BAC);
	if (res[2] == AA)
		return (BAB);
	return (CAB);
}

int	get_extreme_value_idx(int	*arr, int size, int cmp)
{
	int	min_idx;
	int	i;

	min_idx = 0;
	i = 0;
	while (++i < size)
	{
		if (cmp2(arr[min_idx], arr[i], cmp) == BA)
			min_idx = i;
	}
	return (min_idx);
}
