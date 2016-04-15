/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:50:33 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 09:27:58 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectadd(t_vector *v, void *item)
{
	int			newcapacity;

	if (!v)
		v = ft_vectnew();
	if (v->total >= v->capacity)
	{
		newcapacity = v->capacity + VECTOR_CAPACITY;
		v->items = ft_realloc(v->items, v->capacity, newcapacity);
		v->capacity = newcapacity;
	}
	v->items[v->total] = item;
	v->total++;
}
