/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectaddfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 09:49:54 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 11:19:59 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_vectaddfront(t_vector *v, void *item)
{
	int		i;

	ft_vectresize(v);
	if (v->total > 0)
	{
		i = v->total + 1;
		while (i)
		{
			v->items[i] = v->items[i - 1];
			i--;
		}
	}
	v->items[0] = item;
	v->total++;
}
