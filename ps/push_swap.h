/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 19:02:46 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ds/ds_push_swap_set/push_swap_set.h"
# include "push_swap_commands/push_swap_command.h"
# include "push_swap_merge_sort/merge_sort.h"
# include "../libft/ft_printf/ft_printf.h"

enum e_is_error
{
	ERROR,
	NORMAL
};

// process_input
t_dequeue	*process_input(int argc, char **argv);

// sort for exceptional cases
void		ps_sort_exceptional_cases(t_ps_set *set);

void		ps_reduce_commands(t_dequeue *cmds);

#endif