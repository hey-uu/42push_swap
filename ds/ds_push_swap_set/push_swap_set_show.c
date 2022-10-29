/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_show.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:45:42 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 10:45:43 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ft_printf/ft_printf.h"
#include "push_swap_set.h"

static void	cmd_show(t_dequeue *cmds);

void	ps_set_show(t_ps_set *set, int map_opt, int stack_opt, int cmd_opt)
{
	ft_printf("\n====current ps_set=====================================\n");
	if (map_opt == ON)
	{
		ft_printf("[map]\n");
		ft_printf("-----------------------------------------\n");
		trg_map_show_2(set->map);
		ft_printf("-----------------------------------------\n");
	}
	if (stack_opt == ON)
	{
		ft_printf("\n[stack a]\n");
		dq_show(set->stack_a);
		ft_printf("\n[stack b]\n");
		dq_show(set->stack_b);
	}
	if (cmd_opt == ON)
		cmd_show(set->commands);
	ft_printf("\n=======================================================\n");
}

void	cmd_show(t_dequeue *cmds)
{
	const char	tab[12][4] = {"pa", "pb", "ss", "sa", "sb", "ra", "rb", "rr", \
							"rra", "rrb", "rrr", "none"};
	int			i;
	int			j;

	ft_printf("\n[stored commands]");
	ft_printf("\n-----------------------------------------\n");
	i = -1;
	while (i < cmds->used_size)
	{
		j = -1;
		while (++j < 10 && ++i < cmds->used_size)
		{
			ft_printf("%-5s  ", tab[cmds->arr[(cmds->front + i) % cmds->size]]);
		}
		ft_printf("\n");
	}
	ft_printf("\n-----------------------------------------\n");
}
