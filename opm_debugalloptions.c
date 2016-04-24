/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_debugalloptions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:02:21 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/24 11:16:57 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	debugcontent(t_opm_option *option)
{
	int			i;

	ft_putstr("\noption: ");
	ft_putendl(option->name);
	ft_putstr("aliases: ");
	i = 0;
	if (option->aliases)
	{
		while (option->aliases[i])
		{
			i >= 1 ? ft_putstr(", ") : 1;
			ft_putstr(option->aliases[i]);
			i++;
		}
		ft_putendl("");
	}
	else
		ft_putendl("No Alias");
	option->is_set == true ? ft_putendl("is set") : ft_putendl("is not set");
	ft_putstr("require params: "); option->has_params ? ft_putendl("YES") : ft_putendl("NO");
	ft_putendl("\n-------------------");
}

void		opm_debugalloptions(t_opm_params *params)
{
	ft_putendl("___________________________________________________");
	ft_vectforeach(params->options, (void *)&debugcontent);
}
