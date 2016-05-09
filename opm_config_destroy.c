/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_config_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:26:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/24 16:26:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		opm_config_destroy_item(void *this)
{
	if (!this)
		return ;
	if (((t_opm_option *)this)->aliases)
		ft_delsplit(((t_opm_option *)this)->aliases);
	free((t_opm_option *)this);
	this = NULL;
}

void			opm_config_destroy(t_vector *this)
{
	if (!this)
		return ;
	ft_vectdel(this, &opm_config_destroy_item);
}
