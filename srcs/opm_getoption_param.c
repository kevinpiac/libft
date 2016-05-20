/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_getoption_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:22:15 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 14:23:02 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*opm_getoption_param(t_opm_params *params, int index)
{
	t_opm_option *option;

	if (params)
	{
		option = (t_opm_option *)vector_get(params->config, index);
		return (option->param);
	}
	return (NULL);
}
