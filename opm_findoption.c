/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_findoption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:32:49 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 16:14:54 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_opm_option	*opm_findoption(t_opm_params *params, char *name)
{
	t_opm_option	*option;
	int				i;
	int				j;

	i = 0;
	if (params)
	{
		while (i < params->config->total)
		{
			option = opm_getoption(params, i);
			if (ft_strequ(option->name, name))
				return (option);
			else if (option->aliases)
			{
				j = 0;
				while (option->aliases[j])
				{
					if (ft_strequ(option->aliases[j], name))
						return (option);
					j++;
				}
			}
			i++;
		}
	}
	return (NULL);
}
