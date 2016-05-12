/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:20:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:21:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			vector_bubblesort(t_vector *this, int (*cmp)(void *, void *),
				int order)
{
	int			i;
	int			j;
	void		*tmp;

	i = 0;
	while (i < this->total)
	{
		j = 0;
		while (j < this->total - 1)
		{
			if ((cmp(this->items[j], this->items[j + 1]) && order == 1) ||
			(!cmp(this->items[j], this->items[j + 1]) && order == -1))
			{
				tmp = this->items[j];
				this->items[j] = this->items[j + 1];
				this->items[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
