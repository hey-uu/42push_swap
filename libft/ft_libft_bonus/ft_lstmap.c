/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:53 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 09:09:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cur;

	if (!lst || !f)
		return (FT_NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (FT_NULL);
	cur = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		cur->next = ft_lstnew(f(lst->content));
		cur = cur->next;
		if (!cur)
		{
			ft_lstclear(&new_lst, del);
			return (FT_NULL);
		}
	}
	return (new_lst);
}
