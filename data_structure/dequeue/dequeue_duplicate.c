/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:56:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 13:56:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dequeue.h"
#include <stdlib.h>

t_dequeue	*dq_duplicate(t_dequeue *src)
{
	t_dequeue	*dest;
	int			i;

	if (!src)
		return (FT_NULL);
	dest = dq_create_dequeue(src->used_size);
	if (!dest)
		return (FT_NULL);
	i = -1;
	while (++i < src->used_size)
	{
		dq_push_rear(dest, src->arr[(src->front + i) % src->size]);
	}
	return (dest);
}
