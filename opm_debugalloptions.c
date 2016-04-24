/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_debugalloptions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:02:21 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/24 19:40:11 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	debugcontent(t_opm_option *option)
{
	int			i;

	ft_putstr("option:		"); ft_putendl(option->name);
	ft_putstr("aliases:	");
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
		ft_putendl("NO");
	option->is_set == true ? ft_putendl("is set:		YES") : ft_putendl("is set:		NO");
	if (option->req_params)
	{
		ft_putendl("require param:	YES");
		if (option->param)
		{
			ft_putstr("param:		");
			ft_putendl(option->param);
		}
		else
			ft_putendl("param:		NULL");
	}
	else
		 ft_putendl("require param:	NO");
	ft_putendl("\n-------------------");
}

void		opm_debugalloptions(t_opm_params *params)
{
	ft_putendl("___________________________________________________");
	ft_putendl("Passed params: ");
	ft_vectshowall(params->params);
	ft_putendl("___________________________________________________");
	ft_vectforeach(params->options, (void *)&debugcontent);

}
