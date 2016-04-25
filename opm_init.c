/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 16:25:26 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_opm_params		*opm_init(t_vector *arm, t_vector *config)
{
	t_opm_params	*opm;

	(void)arm;
	(void)config;
	opm = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);
	ft_putstr("OPM INIT.");
	return (opm);
}
