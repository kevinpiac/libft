/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 20:09:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/28 20:40:56 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmplst;

	if (!(newlst = ft_memalloc(sizeof(t_list *))))
		return (NULL);
	while (lst)
	{
		if (!(tmplst = f(lst)))
			return (NULL);
		ft_lstadd(&lst, tmplst);
		free(tmplst);
		lst = lst->next;
	}
	return (newlst);
}
