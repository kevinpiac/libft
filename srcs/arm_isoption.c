/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_isoption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:06:00 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 14:15:08 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		arm_isoption(t_arm_argument *arg)
{
	if (ft_strequ(arg->type, "option") || ft_strequ(arg->type, "opt_alias"))
		return (true);
	return (false);
}
