/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 16:17:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dequeue.h"
#include "../../libft/ft_printf/ft_printf.h"

void	dq_show(t_dequeue *deq)
{
	int	i;

	i = -1;
	ft_printf("-----------------------------------------\n");
	ft_printf("size: %d, used_size: %d, front: %d, rear: %d\n", \
		deq->size, deq->used_size, deq->front, deq->rear);
	ft_printf("val| id : data\n");
	while (++i < deq->size)
	{
		ft_printf("       %d : %d\n", \
			(deq->front + i) % deq->size, \
			deq->arr[(deq->front + i) % deq->size]);
	}
	ft_printf("-----------------------------------------\n");
}
