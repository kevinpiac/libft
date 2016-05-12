/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:05:38 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 15:17:55 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_insert(t_vector *this, void *item, int index)
{
	int		i;

	vector_resize(this);
	i = this->total + 1;
	while (i && i > index)
	{
		this->items[i] = this->items[i - 1];
		i--;
	}
	this->items[i] = item;
	this->total++;
}
