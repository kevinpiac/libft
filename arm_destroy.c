/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:26:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/24 16:26:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		arm_destroy_item(void *this)
{
	if ((t_vector *)this)
		free((t_vector *)this);
	this = NULL;
}

void			arm_destroy(t_vector *this)
{
	ft_vectdel(this, &arm_destroy_item);
}
