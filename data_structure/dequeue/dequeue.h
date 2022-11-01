/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:30 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 21:47:28 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_H
# define DEQUEUE_H

# ifndef FT_LONG_MAX
#  define FT_LONG_MAX 9223372036854775807L
# endif

# ifndef FT_INT_MAX
#  define FT_INT_MAX 2147483647
# endif

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

enum e_deq_loc {
	FRONT,
	REAR
};

typedef struct s_dequeue
{
	int	*arr;
	int	front;
	int	rear;
	int	size;
	int	used_size;
}	t_dequeue;

// dequeue_generate
t_dequeue	*dq_create_dequeue(int initial_size);
int			dq_double_size(t_dequeue *dequeue);

// dequeue_duplicate
t_dequeue	*dq_duplicate(t_dequeue *src);

// dequeue_push_or_pop
void		dq_push_front(t_dequeue *dequeue, int new_data);
void		dq_push_rear(t_dequeue *dequeue, int new_data);
int			dq_pop_front(t_dequeue *dequeue);
int			dq_pop_rear(t_dequeue *dequeue);

// dequeue_get_value
long		dq_get_value(t_dequeue *deq, int loc, int idx);
void		dq_get_values(t_dequeue *deq, int *arr, int loc, int size);

// dequeue_show
void		dq_show(t_dequeue *dequeue);
#endif