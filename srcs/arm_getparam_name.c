/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_getparam_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:32:40 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 13:33:49 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*arm_getparam_name(t_vector *arm, int index)
{
	t_arm_argument *param;

	param = arm_getparam(arm, index);
	if (param)
		return (param->name);
	return (NULL);
}
