/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_generate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:56:56 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 11:12:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dequeue.h"
#include <stdlib.h>

t_dequeue	*dq_create_dequeue(int initial_size)
{
	t_dequeue	*deq;

	deq = malloc(sizeof(t_dequeue));
	if (!deq)
		return (FT_NULL);
	deq->size = initial_size;
	deq->used_size = 0;
	deq->front = 0;
	deq->rear = 0;
	deq->arr = malloc(sizeof(int) * deq->size);
	if (!deq->arr)
		return (FT_NULL);
	return (deq);
}

int	dq_double_size(t_dequeue *deq)
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * deq->size * 2);
	if (!new_arr)
		return (0);
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

void	dq_destroy_dequeue(t_dequeue *deq)
{
	if (!deq)
		return ;
	free(deq->arr);
	free(deq);
}
