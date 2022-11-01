/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:26:46 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:41:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char *argvs[])
{
	t_dequeue	*input;
	t_ps_set	*ps_set;
	t_error		res;

	if (argc <= 1)
		return (0);
	input = process_input(argc, argvs);
	if (!input)
		terminate_checker(ERROR);
	ps_set = ps_set_create(input);
	res = NORMAL;
	checker_implement_commands(ps_set, &res);
	if (res == ERROR || res == WRONG)
		terminate_checker(res);
	check_whether_a_is_sorted(ps_set->stack_a);
	terminate_checker(NORMAL);
}
