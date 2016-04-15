/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:50:33 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 10:43:19 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectadd(t_vector *v, void *item)
{
	ft_vectresize(v);
	v->items[v->total] = item;
	v->total++;
}
