/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/28 21:25:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dequeue.h"

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

void	dq_get_values(t_dequeue *deq, int *arr, int loc, int size)
{
	long	tem;
	int		i;

	i = -1;
	while (++i < size)
	{
		tem = dq_get_value(deq, loc, i);
		if (tem == FT_LONG_MAX)
			break ;
		arr[i] = (int)tem;
	}
}
