/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:27 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/14 22:30:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vectnew(void)
{
	t_vector	*vector;

	if (!(vector = ft_memalloc(sizeof(t_vector) * VECTOR_CAPACITY)))
		return (NULL);
	if (!(vector->items = ft_memalloc(sizeof(void *) * VECTOR_CAPACITY)))
		return (NULL);
	vector->total = 0;
	vector->capacity = VECTOR_CAPACITY;
	return (vector);
}
