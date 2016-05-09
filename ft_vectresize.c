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

void			ft_vectresize(t_vector *v)
{
	void			**new;

	if (v->total >= v->capacity)
	{
		if (!(new = (void **)malloc(sizeof(void *) * (v->capacity * 2))))
			return ;
		ft_memcpy(new, v->items, (v->capacity * sizeof(void *)));
		free(v->items);
		v->capacity *= 2;
		v->items = new;
	}
}
