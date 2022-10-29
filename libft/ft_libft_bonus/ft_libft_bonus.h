/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:08:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/29 09:13:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LIBFT_BONUS_H
# define FT_LIBFT_BONUS_H

# ifndef FT_NULL
#  define FT_NULL	 (void *) 0
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// linked list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

#endif