/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:14:22 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/26 15:52:02 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		opm_putaliases(char	**aliases)
{
	int				i;

	i = 0;
	if (aliases)
	{
		while (aliases[i])
		{
			i > 0 ? ft_putstr(",") : 1;
			ft_putstr(aliases[i]);
			i++;
		}
	}
	else
		ft_putstr("NULL");
	ft_putchar('\n');
}

static void		opm_putdata(t_opm_option *option)
{
	static int		i;

	i = (i ? i : 0);
	ft_putnbr(i);
	ft_putstr("	| name ->	");
	ft_putstr(option->name);
	ft_putstr("	| aliases -> ");
	opm_putaliases(option->aliases);
	ft_putstr("	| is_set ->	");
	ft_putstr(option->is_set ? "TRUE" : "FALSE");
	ft_putstr("	| req_param -> ");
	ft_putendl(option->req_params ? "TRUE" : "FALSE");
	ft_putstr("	| param ->	");
	ft_putendl(option->param ? option->param : "NULL");
	ft_putendl("	-----------------------------------------------");
	i++;
}

void			opm_debug(t_opm_params *opm)
{
	ft_putstr("\n\nOPM __total__ (");
	ft_putnbr(opm->config->total);
	ft_putstr(")	__set__ (");
	ft_putnbr(opm->total_set);
	if (opm->error)
	{
		ft_putstr(")	__ERROR_CODE__ (");
		ft_putnbr(opm->error_code);
	}
	ft_putendl(")\n");
	ft_vectforeach(opm->config, (void *)&opm_putdata);
	ft_putstr("\n\n");
}
