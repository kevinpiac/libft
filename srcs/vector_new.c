/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:27 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/14 22:30:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_new(size_t init_capacity)
{
	t_vector	*vector;
	size_t		capacity;

	capacity = init_capacity ? init_capacity : VECTOR_DEFAULT_CAPACITY;
	if (!(vector = ft_memalloc(sizeof(t_vector) * 1)))
		return (NULL);
	if (!(vector->items = ft_memalloc(sizeof(void *) * capacity)))
		return (NULL);
	vector->total = 0;
	vector->capacity = capacity;
	return (vector);
}
