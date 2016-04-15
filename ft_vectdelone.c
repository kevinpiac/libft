/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:39:14 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 15:37:33 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectdelone(t_vector *v, int index)
{
	int		i;

	if (index > v->total)
		return ;
	if (index == v->total)
		v->items[index] = NULL;
	else
	{
		i = index;
		while (i < v->total - 1)
		{
			v->items[i] = v->items[i + 1];
			i++;
		}
		v->items[v->total] = NULL;
	}
	v->total--;
}
