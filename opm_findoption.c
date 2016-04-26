/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_findoption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:32:49 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/26 15:36:18 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_opm_option	*opm_findoption(t_vector *options, char *name)
{
	t_opm_option	*option;
	int				i;
	int				j;

	i = 0;
	while (i < options->total)
	{
		option = ft_vectget(options, i);
		if (ft_strequ(name, option->name))
			return (option);
		else if (option->aliases)
		{
			j = 0;
			while (option->aliases[j])
			{
				if (ft_strequ(name, option->aliases[j]))
					return (option);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
