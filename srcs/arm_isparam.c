/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_isparam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:45:53 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 13:47:03 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		arm_isparam(t_arm_argument *arg)
{
	if (ft_strequ(arg->type, "param"))
		return (true);
	return (false);
}
