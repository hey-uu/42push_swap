/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 14:52:33 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SET_H
# define PUSH_SWAP_SET_H

# include "../ds_dequeue/ft_dequeue.h"
# include "../ds_triangle_map/triangle_map.h"

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

enum e_option_on_off
{
	ON,
	OFF
};

typedef struct s_ps_set
{
	t_trg_map	*map;
	t_dequeue	*stack_a;
	t_dequeue	*stack_b;
	t_dequeue	*commands;	
}	t_ps_set;

// push_swap_set_generate
t_ps_set	*ps_set_create(t_dequeue *input);
void		ps_set_destroy(t_ps_set *set);

// push_swap_set_show
void		ps_set_show(t_ps_set *set, int map_opt, int stack_opt, int cmd_opt);

#endif