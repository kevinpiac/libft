/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 10:42:27 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			option_new(t_vector *options_container, char *option)
{
	t_opm_option	*progoption;
	char			**options;
	char			*ret;

	options = ft_strsplit(option, '|');
	progoption = (t_opm_option *)ft_memalloc(sizeof(t_opm_option) * 1);
	if ((ret = ft_strchr(options[0], ':')))
	{
		progoption->name = ft_strsub(options[0], 0, (ft_strlen(options[0]) - 1));
		progoption->req_params = true;
	}
	else
	{
		progoption->name = options[0];
		progoption->req_params = false;
		progoption->params_nb = 0;
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

static t_bool		set_option(t_opm_option *option, char *opt_param)
{
	if (!option)
		return (false);
	if (opt_param)
		option->param = ft_strdup(opt_param);
	else
		option->param = NULL;
	option->is_set = true;
	return (true);
}

static void			opm_checkalias(t_opm_params *params, char **av, int i, int ac)
{
	char			*opt_param;
	t_opm_option	*option;

	option = opm_findoption(params, &av[i][2]);
	if (option && option->req_params && i + 1 < ac)
		opt_param = av[i + 1];
	else
		opt_param = NULL;
	if (!set_option(option, opt_param))
		ft_putstr("error unknown option");
}

static void			opm_checkoptions(t_opm_params *params, char **av, int i, int ac)
{
	int				j;
	char			*opt_param;
	t_opm_option	*option;
	char			*tmp;

	j = 1;
	while (av[i][j])
	{
		tmp = ft_strsub(av[i], j, 1);
		option = opm_findoption(params, tmp);
		free(tmp);
		if (option && option->req_params && i + 1 < ac)
			opt_param = av[i + 1];
		else
			opt_param = NULL;
		if (!set_option(option, opt_param))
			ft_putstr("error unknown option");
		j++;
	}
}

t_opm_params		*opm_init(char *opt_conf, int ac, char **av)
{
	t_opm_params	*params;
	int				i;

	params = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);
	params->options = progoptions_init(opt_conf);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 2 && av[i][1] == '-')
			opm_checkalias(params, av, i, ac);
		else if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
			opm_checkoptions(params, av, i, ac);
		else
		{
			if (!params->params)
				params->params = ft_vectnew();
			ft_vectadd(params->params, av[i]);
		}
		i++;
	}
	return (params);
}
