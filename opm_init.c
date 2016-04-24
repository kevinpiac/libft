/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/24 11:16:48 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			option_new(t_vector *options_container, char *option)
{
	t_opm_option	*progoption;
	char			**options;

	options = ft_strsplit(option, '|');
	progoption = (t_opm_option *)ft_memalloc(sizeof(t_opm_option) * 1);
	if (ft_strchr(options[0], ':'))
	{
		progoption->name = ft_strsub(options[0], 0, (ft_strlen(options[0]) - 1));
		progoption->has_params = true;
	}
	else
	{
		progoption->name = options[0];
		progoption->has_params = false;
	}
	if (options[1])
		progoption->aliases = &options[1];
	else
		progoption->aliases = NULL;
	ft_vectadd(options_container, progoption);
}

static t_vector		*progoptions_init(char *opt_conf)
{
	t_vector		*options;
	char			**conf;
	int				i;

	i = 0;
	conf = ft_strsplit(opt_conf, ',');
	options = ft_vectnew();
	while (conf[i])
	{
		option_new(options, conf[i]);
		i++;
	}
	return (options);
}

t_opm_params		*opm_init(char *opt_conf, int ac, char **av)
{
	t_opm_params	*params;
	t_opm_option	*option;
	int				i;
	int				j;

	params = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);
	params->options = progoptions_init(opt_conf);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && ft_strlen(av[i]) > 2)
		{
			if ((option = opm_findoption(params, &av[i][2])))
				option->is_set = true;
			else
				ft_putendl("ERROR\n"); // exit with error.
		}
		else if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
		{
			j = 1;
			while (av[i][j])
			{
				if ((option = opm_findoption(params, ft_strsub(av[i], j, 1))))
					option->is_set = true;
				else
					ft_putendl("ERROR\n"); // exit with error.
				j++;
			}
		}
		i++;
	}
	return (params);
}
