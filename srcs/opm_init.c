/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/28 14:44:23 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_for_option(t_vector *arm, int i, t_opm_params *opm,
					t_vector *config)
{
	t_opm_option	*opm_option;
	t_arm_argument	*opt_param;
	t_arm_argument	*option;
	int				ret;

	ret = i;
	option = vector_get(arm, i);
	if ((opm_option = opm_findoption(config, option->name)))
	{
		if (opm_option->req_params && i + 1 < arm->total)
		{
			opt_param = vector_get(arm, i + 1);
			opt_param->type = "opt_param";
			opm_option->param = opt_param->name;
			ret++;
		}
		opm_option->is_set = true;
		opm->total_set++;
	}
	else
		opm_error("You passed a non supported parameter.");
	return (ret);
}

t_opm_params		*opm_init(t_vector *arm, t_vector *config)
{
	t_opm_params	*opm;
	t_arm_argument	*option;
	int				i;

	i = 1;
	opm = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);
	opm->params = vector_new(0);
	while (i < arm->total)
	{
		option = arm->items[i];
		if (arm_isoption(option))
			i = check_for_option(arm, i, opm, config);
		else if (!arm_isoption(option))
		{
			vector_add(opm->params, option);
		}
		i++;
	}
	opm->config = config;
	return (opm);
}
