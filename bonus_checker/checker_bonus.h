/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:14:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:47:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include "../libft/ft_get_next_line/get_next_line.h"
# include "../libft/ft_libft_mandatory/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "dequeue_bonus.h"
# include "push_swap_set_bonus.h"
# include "command_bonus.h"
# include "process_inputs_bonus.h"

typedef enum e_checker_error
{
	NORMAL = 0,
	ERROR = 1,
	WRONG = 2,
	NOT_CMD = 11
}	t_error;

void	terminate_checker(t_error is_error);
void	check_whether_a_is_sorted(t_dequeue *stack_a);
t_error	checker_implement_commands(t_ps_set *set, t_error *res);
int		get_command(char *str);

#endif
