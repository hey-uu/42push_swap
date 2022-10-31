/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:47:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/31 21:53:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_malloc(size_t size_of)
{
	void	*new;

	new = malloc(size_of);
	if (!new)
		ft_exit(FT_NULL, 1);
	return (new);
}
