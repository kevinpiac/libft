/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:09:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/01 09:12:18 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmplst;

	newlst = ft_lstnew(NULL, 0);
	tmplst = newlst;
	while (lst)
	{
		if (!(tmplst = f(lst)))
			return (NULL);
		ft_lstadd(&newlst, tmplst);
		lst = lst->next;
		tmplst = tmplst->next;
	}
	free(tmplst);
	return (newlst);
}
