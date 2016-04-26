/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/26 16:12:13 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_opm_params		*opm_init(t_vector *arm, t_vector *config)
{
	t_opm_params	*opm;
	t_arm_argument	*option;
	t_arm_argument	*opt_param;
	t_opm_option	*opm_option;
	int				i;

	i = 1;
	opm = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);
	while (i < arm->total)
	{
		option = ft_vectget(arm, i);
		if (ft_strequ(option->type, "option") ||
			ft_strequ(option->type, "opt_alias")) // replace by binary mask macro.
		{
			if ((opm_option = opm_findoption(config, option->name)))
			{
				if (opm_option->req_params && i + 1 < arm->total)
				{
					opt_param = ft_vectget(arm, i + 1);
					opm_option->param = opt_param->name;
					i++;
				}
				opm_option->is_set = true;
				opm->total_set++;
			}
			else
			{
				opm->error = true;
				opm->error_code = -1;
			}
		}
		i++;
	}
	opm->config = config;
	return (opm);
}
