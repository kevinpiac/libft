/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 09:59:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/04 10:25:51 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	if (*alst == NULL)
	{
		*alst = ft_lstnew(NULL, 0);
		*alst = new;
		(*alst)->next = NULL;
		return ;
	}
	while ((*alst)->next)
		*alst = (*alst)->next;
	if (*alst && new)
		(*alst)->next = new;
}
