/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reduce_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:32:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 21:25:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_remove_all_reducables(t_dequeue *cmds, int reduced, int changed);
static void	ps_check_reducables(t_dequeue *cmds, int i[], int cnt[], int cmd);
static void	ps_remove_reducables(t_dequeue *cmds, int i[], int cnt[], int cmd);

void	ps_reduce_commands(t_dequeue *cmds)
{
	ps_remove_all_reducables(cmds, PA, NON);
	ps_remove_all_reducables(cmds, RA, RR);
	ps_remove_all_reducables(cmds, RRA, RRR);
	ps_remove_all_reducables(cmds, SA, SS);
}

void	ps_remove_all_reducables(t_dequeue *cmds, int reduced, int changed)
{
	int	idx[3];
	int	cnt[2];
	int	value;

	idx[0] = 0;
	while (idx[0] < cmds->used_size)
	{
		cnt[0] = 0;
		cnt[1] = 0;
		value = dq_get_value(cmds, FRONT, idx[0]);
		if (value == reduced || value == (reduced + 1))
			ps_check_reducables(cmds, idx, cnt, reduced);
		else
			idx[0] += 1;
		ps_remove_reducables(cmds, idx, cnt, changed);
	}
}

void	ps_check_reducables(t_dequeue *cmds, int idx[], int cnt[], int cmd)
{
	const int	val = dq_get_value(cmds, FRONT, idx[0]);

	while (idx[0] < cmds->used_size && dq_get_value(cmds, FRONT, idx[0]) == val)
	{
		cnt[0] += 1;
		idx[0] += 1;
	}
	idx[2] = idx[0];
	while (idx[0] < cmds->used_size && dq_get_value(cmds, FRONT, idx[0]) \
			== (val + (val == cmd) - (val == (cmd + 1))))
	{
		cnt[1] += 1;
		idx[0] += 1;
	}
}

void	ps_remove_reducables(t_dequeue *cmds, int idx[], int cnt[], int cmd)
{
	idx[1] = 0;
	while (idx[1] < cnt[0] && idx[1] < cnt[1])
	{
		cmds->arr[(idx[2] + idx[1]) % cmds->size] = NON;
		cmds->arr[(idx[2] - 1 - idx[1] + cmds->size) % cmds->size] = cmd;
		idx[1] += 1;
	}
}
