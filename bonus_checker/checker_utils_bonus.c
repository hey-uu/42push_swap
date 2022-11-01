/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:33:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:34:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	terminate_checker(t_error is_error)
{
	if (is_error == ERROR)
		ft_printf("Error\n");
	else if (is_error == WRONG)
	{
		ft_printf("KO\n");
		is_error = NORMAL;
	}
	else if (is_error == NORMAL)
	{
		ft_printf("OK\n");
	}
	exit(is_error);
}

void	check_whether_a_is_sorted(t_dequeue *stack_a)
{
	int	i;
	int	cur_data;
	int	nxt_data;

	i = 0;
	if (stack_a->used_size != stack_a->size)
		terminate_checker(WRONG);
	cur_data = dq_get_value(stack_a, FRONT, 0);
	while (++i < stack_a->used_size)
	{
		nxt_data = dq_get_value(stack_a, FRONT, i);
		if (cur_data > nxt_data)
			terminate_checker(WRONG);
		else if (cur_data == nxt_data)
			terminate_checker(ERROR);
		cur_data = nxt_data;
	}
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
		else if (fcts[cmd](set) == 0)
			*res = WRONG;
		free(line);
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
