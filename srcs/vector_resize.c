/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 09:56:05 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 10:44:20 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			vector_resize(t_vector *this)
{
	void			**new;

	if (this->total >= this->capacity)
	{
		if (!(new = (void **)malloc(sizeof(void *) * (this->capacity * 2))))
			return ;
		ft_memcpy(new, this->items, (this->capacity * sizeof(void *)));
		free(this->items);
		this->capacity *= 2;
		this->items = new;
	}
}
