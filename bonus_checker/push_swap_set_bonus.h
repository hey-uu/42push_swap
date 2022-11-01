/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:32:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SET_BONUS_H
# define PUSH_SWAP_SET_BONUS_H

# include "dequeue_bonus.h"

typedef struct s_ps_set
{
	t_dequeue	*stack_a;
	t_dequeue	*stack_b;
}	t_ps_set;

// push_swap_set_generate
t_ps_set	*ps_set_create(t_dequeue *input);

#endif