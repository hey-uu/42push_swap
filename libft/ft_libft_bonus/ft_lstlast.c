/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:46 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 09:10:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (FT_NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
