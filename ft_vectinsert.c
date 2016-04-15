/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:05:38 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 13:46:04 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectinsert(t_vector *v, void *item, int index)
{
	int		i;

	ft_vectresize(v);
	i = v->total + 1;
	while (i && i > index)
	{
		v->items[i] = v->items[i - 1];
		i--;
	}
	v->items[i] = item;
	v->total++;
}
