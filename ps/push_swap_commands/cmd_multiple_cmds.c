/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_multiple_cmds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:05:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 13:17:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_command.h"

void	implement_commands(t_ps_set *set, const int *command, int cmd_size)
{
	const t_cmd	cmd_fcts[11] = {pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr};
	int			i;

	i = -1;
	while (++i < cmd_size)
	{
		if (command[i] != NON)
			cmd_fcts[command[i]](set);
	}
}

void	push_all(t_ps_set *set, int cmd)
{
	if (cmd == PB)
	{
		while (set->stack_a->used_size != 0)
			pb(set);
	}
	else if (cmd == PA)
	{
		while (set->stack_b->used_size != 0)
			pa(set);
	}
}

void	push_n_elements(t_ps_set *set, int number, int cmd)
{
	int	i;

	i = -1;
	while (++i < number)
	{
		if (cmd == PA)
			pa(set);
		else
			pb(set);
	}
}
