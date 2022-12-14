/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:45:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 22:45:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue_bonus.h"

void	dq_push_front(t_dequeue *deq, int new_data)
{
	if (deq->used_size == deq->size)
		dq_double_size(deq);
	deq->front = (deq->front - 1 + deq->size) % deq->size;
	if (deq->used_size == 0)
		deq->rear = (deq->front + 1) % deq->size;
	deq->arr[deq->front] = new_data;
	deq->used_size++;
}

void	dq_push_rear(t_dequeue *deq, int new_data)
{
	if (deq->used_size == deq->size)
		dq_double_size(deq);
	deq->arr[deq->rear] = new_data;
	deq->rear = (deq->rear + 1) % deq->size;
	deq->used_size++;
}

int	dq_pop_front(t_dequeue *deq)
{
	int	popped;

	popped = deq->arr[deq->front];
	deq->front = (deq->front + 1) % deq->size;
	deq->used_size--;
	return (popped);
}

int	dq_pop_rear(t_dequeue *deq)
{
	int	popped;

	deq->rear = (deq->rear - 1 + deq->size) % deq->size;
	popped = deq->arr[deq->rear];
	deq->used_size--;
	return (popped);
}