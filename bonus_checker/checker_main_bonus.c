/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:26:46 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:38:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

int	main(int argc, char *argvs[])
{
	t_dequeue	*input;
	t_ps_set	*ps_set;
	t_error		res;

	if (argc <= 1)
		return (0);
	input = process_input(argc, argvs);
	if (!input)
		return (terminate_checker(ERROR));
	ps_set = ps_set_create(input);
	res = NORMAL;
	checker_implement_commands(ps_set, &res);
	if (res == ERROR || res == WRONG)
		return (terminate_checker(res));
	if (is_well_sorted(ps_set->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (terminate_checker(NORMAL));
}

t_error	terminate_checker(t_error is_error)
{
	if (is_error == ERROR)
		ft_printf("Error\n");
	if (is_error == WRONG)
	{
		ft_printf("KO\n");
		is_error = NORMAL;
	}
	exit(is_error);
	return (is_error);
}

int	is_well_sorted(t_dequeue *stack_a)
{
	int	i;
	int	cur_data;
	int	nxt_data;

	i = 0;
	if (stack_a->used_size != stack_a->size)
		return (NO);
	cur_data = dq_get_value(stack_a, FRONT, 0);
	while (++i < stack_a->used_size)
	{
		nxt_data = dq_get_value(stack_a, FRONT, i);
		if (cur_data > nxt_data)
			return (NO);
		cur_data = nxt_data;
	}
	return (YES);
}

t_error	checker_implement_commands(t_ps_set *set, t_error *res)
{
	const t_cmd	fcts[11] = {pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr};
	char		*line;
	int			cmd;

	line = get_next_line(0);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		cmd = get_command(line);
		if (cmd == NOT_CMD)
			*res = ERROR;
		if (fcts[cmd](set) == 0)
			*res = WRONG;
		free(line);
		line = get_next_line(0);
		if (!line)
			line = get_next_line(0);
	}
	return (NORMAL);
}

int	get_command(char *str)
{
	const char	*cmd[11] = {"pa", "pb", "sa", "sb", "ss", \
							"ra", "rb", "rr", "rra", "rrb", "rrr"};
	const int	len = ft_strlen(str);
	int			i;

	i = -1;
	while (++i < 11)
	{
		if (ft_memcmp(str, cmd[i], len) == 0 && \
			ft_memcmp(str, cmd[i], ft_strlen(cmd[i])) == 0)
			return (i);
	}
	return (i);
}
