/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectbubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:20:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:21:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_vectbubblesort(t_vector *v, int(*cmp)(void *, void *))
{
    int			i;
	int 		j;
    void        *tmp;

	i = 0;
	while (i < v->total)
	{
		j = 0;
		while (j < v->total - 1)
		{
			if (cmp(v->items[j], v->items[j + 1]))
			{
				tmp = v->items[j];
				v->items[j] = v->items[j + 1];
				v->items[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
