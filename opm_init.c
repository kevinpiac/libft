/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/24 18:31:33 by kpiacent         ###   ########.fr       */
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
/*
static void			set_opt_params(t_opm_option *option, char *params)
{
	char			**opt_params;

	opt_params = ft_strsplit(params, '-');
	option->params = opt_params;
}
*/
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

t_bool				opm_param_is_option(char *param)
{
	if (param[0] == '-' && ft_strlen(param) > 1)
		return (true);
	return (false);
}

t_bool				opm_param_is_alias(char *param)
{
	if (param[0] == '-' && ft_strlen(param) > 2 && param[1] == '-')
		return (true);
	return (false);
}
t_opm_params		*opm_init(char *opt_conf, int ac, char **av)
{
	t_opm_params	*params;
	t_opm_option	*option;
	char			*opt_param;
	int				i;

	params = (t_opm_params *)ft_memalloc(sizeof(t_opm_params) * 1);
	params->options = progoptions_init(opt_conf);
	i = 1;
	while (i < ac)
	{
		if (opm_param_is_alias(av[i]) || opm_param_is_option(av[i]))
		{
			option = opm_param_is_alias(av[i]) ? opm_findoption(params, &av[i][2]) : opm_findoption(params, &av[i][1]);
			if (option && option->req_params && i + 1 < ac)
				opt_param = av[i + 1];
			else
				opt_param = NULL;
			if (!set_option(option, opt_param))
				ft_putstr("error");
		}
		i++;
	}
	return (params);
}
