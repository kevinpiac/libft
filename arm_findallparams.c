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

	params = ft_vectnew();
	i = 0;
	while (i < arm->total)
	{
		arg = ft_vectget(arm, i);
		if (arm_isparam(arg))
			ft_vectadd(params, arg);
		i++;
	}
	return (params);
}
