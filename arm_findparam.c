/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_findparam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:36:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 13:38:19 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arm_argument	*arm_findparam(t_vector *arm, char	*name)
{
	int				i;
	t_arm_argument	*param;

	i = 0;
	while (i < arm->total)
	{
		param = ft_vectget(arm, i);
		if (ft_strequ(param->type, "param"))
		{
			if (ft_strequ(param->name, name))
				return (param);
		}
	}
	return (NULL);
}
