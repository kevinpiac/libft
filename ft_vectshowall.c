/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectshowall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:01:48 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 12:01:57 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectshowall(t_vector *v)
{
	int		i;

	i = 0;
	while (i < v->total)
	{
		ft_putendl(v->items[i]);
		i++;
	}
}
