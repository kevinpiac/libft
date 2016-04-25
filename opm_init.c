/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 18:42:51 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_opm_params		*opm_init(t_vector *arm, t_vector *config)
{
	t_opm_params	*opm;
	t_opm_option	*option;
	int				i;

	i = 1;
	opm = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);

	while (i < arm->total)
	{
		option = ft_vectget(arm, i);
		if (!opm_findoption(config, option))
		{
			opm->error = true;
			opm->error_code = -1;
		}
		else
			config_option->is_set = true;
	}
	opm->config = config;
	return (opm);
}
