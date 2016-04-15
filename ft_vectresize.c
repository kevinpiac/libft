/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectresize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 09:56:05 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 10:44:20 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectresize(t_vector *v)
{
	int			newcapacity;

	if (v->total >= v->capacity)
	{
		newcapacity = v->capacity + VECTOR_CAPACITY;
		v->items = realloc(v->items, newcapacity);//ft_realloc(v->items, v->capacity, newcapacity);
		v->capacity = newcapacity;
	}
}
