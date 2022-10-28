/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 14:01:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tem;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tem = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tem, del);
	}
}
