/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 17:13:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../data_structure/push_swap_set/push_swap_set.h"
# include "commands/command.h"
# include "merge_sort/merge_sort.h"
# include "../libft/ft_libft_mandatory/libft.h"
# include "process_inputs.h"

// sort for exceptional cases
void		ps_sort_exceptional_cases(t_ps_set *set);

void		ps_reduce_commands(t_dequeue *cmds);

#endif