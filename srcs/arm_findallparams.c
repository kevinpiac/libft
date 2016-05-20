/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_findallparams.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:59:42 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 14:07:44 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*arm_findallparams(t_vector *arm)
{
	int				i;
	t_arm_argument	*arg;
	t_vector		*params;

	params = vector_new(VECTOR_DEFAULT_CAPACITY);
	i = 0;
	while (i < arm->total)
	{
		arg = vector_get(arm, i);
		if (arm_isparam(arg))
			vector_add(params, arg);
		i++;
	}
	return (params);
}
