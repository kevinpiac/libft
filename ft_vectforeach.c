/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectforeach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:55:25 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 21:10:24 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectforeach(t_vector *v, void *(*f)(void *))
{
	int		i;

	i = 0;
	while (i < v->total)
	{
		f(v->items[i]);
		i++;
	}
}
