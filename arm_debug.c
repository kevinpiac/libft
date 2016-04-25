/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:04:05 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 14:27:09 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		arm_putdata(t_arm_argument *arg)
{
	static	int		i;

	i = (i ? i : 0);
	ft_putnbr(i);
	ft_putstr(" | type -> ");
	ft_putstr(arg->type);
	ft_putstr("	| name -> ");
	ft_putendl(arg->name);
	i++;
}

void			arm_debug(t_vector *arm)
{
	ft_putstr("ARM __total__(");
	ft_putnbr(arm->total);
	ft_putendl(")");
	ft_vectforeach(arm, (void *)&arm_putdata);
}
