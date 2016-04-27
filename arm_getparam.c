/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_getparam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:28:19 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 13:53:41 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arm_argument	*arm_getparam(t_vector *arm, int index)
{
	int				count;
	int				i;
	t_arm_argument	*param;

	count = 0;
	i = 0;
	while (i < arm->total)
	{
		param = ft_vectget(arm, i);
		if (arm_isparam(param))
		{
			if (count == index)
				return (param);
			count++;
		}
		i++;
	}
	return (NULL);
}
