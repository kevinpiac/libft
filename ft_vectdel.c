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

void			ft_vectdel(t_vector *v, void (*del_fn)(void *))
{
	int			i;

	i = 0;
	if (!v)
		return ;
	while (i < v->total)
	{
		del_fn(v->items[i]);
		i++;
	}
	free(v);
}
