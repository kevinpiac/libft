/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_findalloptions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:05:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 14:07:53 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*arm_findalloptions(t_vector *arm)
{
	int				i;
	t_arm_argument	*arg;
	t_vector		*options;

	options = ft_vectnew();
	i = 0;
	while (i < arm->total)
	{
		arg = ft_vectget(arm, i);
		if (arm_isoption(arg))
			ft_vectadd(options, arg);
		i++;
	}
	return (options);
}
