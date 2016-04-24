/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_getoption.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:00:21 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/24 11:17:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_opm_option	*opm_getoption(t_opm_params *params, int index)
{
	t_opm_option *option;

	if (params)
	{
		option = (t_opm_option *)ft_vectget(params->options, index);
		return (option);
	}
	return (NULL);
}
