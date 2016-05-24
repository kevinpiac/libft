/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:20:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:21:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			vector_clear(t_vector *this, void (*del_fn)(void *))
{
	int			i;

	i = this->total;
	if (!this)
		return ;
	while (i >= 0)
	{
		del_fn(this->items[i]);
		i--;
		i == 0 ? this->total : this->total--;
	}
}
