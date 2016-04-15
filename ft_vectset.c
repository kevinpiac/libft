/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:29:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:34:43 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectset(t_vector *v, void *item, int index)
{
	if (index > 0 && index <= v->total)
	{
		v->items[index] = item;
	}
}
