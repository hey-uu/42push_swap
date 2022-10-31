/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:17:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 22:11:10 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	terminate_program(t_ps_set *set, t_dequeue *input, int is_error);
static void	ps_show_commands(t_dequeue *commands);

int	main(int argc, char *argv[])
{
	t_dequeue	*input;
	t_ps_set	*ps_set;

	if (argc <= 1)
		return (0);
	input = process_input(argc, argv);
	ps_set = ps_set_create(input);
	if (ps_set->stack_a->used_size == 1)
		ft_exit("Error\n", 1);
	if (ps_set->stack_a->used_size <= 5)
		ps_sort_exceptional_cases(ps_set);
	else
		ps_merge_sort(ps_set);
	ps_reduce_commands(ps_set->commands);
	ps_show_commands(ps_set->commands);
	exit(0);
}

void	ps_show_commands(t_dequeue *commands)
{
	const char	tab[12][4] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", \
							"rra", "rrb", "rrr"};
	int			i;
	int			cmd;

	i = -1;
	while (++i < commands->used_size)
	{
		cmd = dq_get_value(commands, FRONT, i);
		if (cmd != NON)
			ft_printf("%s\n", tab[dq_get_value(commands, FRONT, i)]);
	}
}
