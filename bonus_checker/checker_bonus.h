/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:14:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 09:30:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include "../libft/ft_get_next_line/get_next_line.h"
# include "../libft/ft_libft_mandatory/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../data_structure/dequeue/ft_dequeue.h"
# include "../data_structure/push_swap_set/push_swap_set.h"
# include "../mandatory_push_swap/process_inputs.h"
# include "../mandatory_push_swap/commands/command.h"

typedef enum e_checker_error
{
	NORMAL = 0,
	ERROR = 1,
	WRONG = 2,
	NOT_CMD = 11
}	t_error;

typedef enum e_is_sorted
{
	NO = 0,
	YES = 1
}	t_is_sorted;

t_error	terminate_checker(t_error is_error);
int		is_well_sorted(t_dequeue *stack_a);
t_error	checker_implement_commands(t_ps_set *set, t_error *res);
int		get_command(char *str);

#endif
