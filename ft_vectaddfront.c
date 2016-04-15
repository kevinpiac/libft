/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectaddfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 09:49:54 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:00:14 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectaddfront(t_vector *v, void *item)
{
	ft_vectresize(v);
	ft_vectinsert(v, item, 0);
}