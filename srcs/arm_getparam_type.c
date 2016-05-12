/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_getparam_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:34:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 13:34:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*arm_getparam_type(t_vector *arm, int index)
{
	t_arm_argument *param;

	param = arm_getparam(arm, index);
	if (param)
		return (param->type);
	return (NULL);
}
