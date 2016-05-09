/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:20:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:21:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vectdel(t_vector *this, void (*del_fn)(void *))
{
	int			i;

	i = 0;
	if (!this)
		return ;
	while (i < this->total)
	{
		del_fn(this->items[i]);
		i++;
	}
	if (this->items)
		free(this->items);
	free(this);
}
