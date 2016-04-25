/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_config_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:55:22 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 16:24:11 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		opm_option_add(t_vector *config, char *option_name)
{
	t_opm_option	*option;
	char			**aliases;
	char			*ret;

	aliases = ft_strsplit(option_name, '|');
	option = (t_opm_option *)ft_memalloc(sizeof(t_opm_option) * 1);
	if ((ret = ft_strchr(aliases[0], ':')))
	{
		option->name = ft_strsub(aliases[0], 0, (ft_strlen(aliases[0]) - 1));
		option->req_params = true;
	}
	else
	{
		option->name = aliases[0];
		option->req_params = false;
	}
	if (aliases[1])
		option->aliases = &aliases[1];
	else
		option->aliases = NULL;
	ft_vectadd(config, option);
}

t_vector		*opm_config_init(char *config_instruct)
{
	t_vector		*config;
	char			**conf;
	int				i;

	i = 0;
	conf = ft_strsplit(config_instruct, ',');
	config = ft_vectnew();
	while (conf[i])
	{
		opm_option_add(config, conf[i]);
		i++;
	}

	return (config);
}
