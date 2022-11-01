/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:56:56 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:46:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue_bonus.h"
#include "../libft/ft_libft_mandatory/libft.h"
#include <stdlib.h>

t_dequeue	*dq_create_dequeue(int initial_size)
{
	t_dequeue	*deq;

	deq = malloc(sizeof(t_dequeue));
	if (!deq)
		ft_exit("Error\n", 1);
	deq->size = initial_size;
	deq->used_size = 0;
	deq->front = 0;
	deq->rear = 0;
	deq->arr = malloc(sizeof(int) * deq->size);
	if (!deq->arr)
		ft_exit("Error\n", 1);
	return (deq);
}

t_dequeue	*dq_duplicate(t_dequeue *src)
{
	t_dequeue	*dest;
	int			i;

	if (!src)
		return (FT_NULL);
	dest = dq_create_dequeue(src->used_size);
	if (!dest)
		ft_exit("Error\n", 1);
	i = -1;
	while (++i < src->used_size)
	{
		dq_push_rear(dest, src->arr[(src->front + i) % src->size]);
	}
	return (dest);
}

int	dq_double_size(t_dequeue *deq)
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * deq->size * 2);
	if (!new_arr)
		ft_exit("Error\n", 1);
	if (deq->used_size != 0)
	{
		i = -1;
		while (++i < deq->used_size)
			new_arr[i] = deq->arr[(deq->front + i) % deq->size];
	}
	deq->front = 0;
	deq->rear = deq->used_size;
	deq->size *= 2;
	free(deq->arr);
	deq->arr = new_arr;
	return (1);
}

long	dq_get_value(t_dequeue *deq, int loc, int idx)
{
	if (deq->used_size <= idx)
		return (FT_LONG_MAX);
	if (loc == FRONT)
		return ((long)deq->arr[(deq->front + idx) % deq->size]);
	else if (loc == REAR)
		return ((long)deq->arr[(deq->rear - 1 - idx + deq->size) % deq->size]);
	return (FT_LONG_MAX);
}
