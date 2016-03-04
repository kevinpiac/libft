/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:09:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/04 10:31:45 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;

	newlst = NULL;
	ft_lstaddback(&newlst, f(lst));
	lst = lst->next;
	while (lst)
	{
		ft_lstaddback(&newlst, f(lst));
		lst = lst->next;
	}
	return (newlst);
}
