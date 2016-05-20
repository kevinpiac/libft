/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:29:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:34:43 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_set(t_vector *this, void *item, int index)
{
	if (index > 0 && index <= this->total)
	{
		this->items[index] = item;
	}
}
