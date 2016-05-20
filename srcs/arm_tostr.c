/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_tostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:44:42 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/04 08:11:01 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*arm_tostr(t_vector *arm)
{
	int				len;
	int				i;
	char			*s;
	t_arm_argument	*item;

	len = 0;
	i = 0;
	while (i < arm->total)
	{
		item = arm->items[i];
		len = len + ft_strlen(item->name);
		i++;
	}
	if (!(s = ft_strnew(len + arm->total - 1)))
		return (NULL);
	i = 0;
	while (i < arm->total)
	{
		item = arm->items[i];
		s = ft_strcat(s, item->name);
		if (i < arm->total - 1)
			ft_strcat(s, " ");
		i++;
	}
	return (s);
}
