/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:28:04 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 15:02:37 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				add_options(char **av, int i, size_t len, t_vector *arm)
{
	size_t		j;

	j = 1;
	while (j < len)
	{
		vector_add(arm, arm_argument_new(ft_strsub(av[i], j, 1),
		"option"));
		j++;
	}
}

static t_bool			set_arg(char **av, int i, t_vector *arm, t_bool force)
{
	size_t		len;
	t_bool		force_param;

	force_param = force;
	len = ft_strlen(av[i]);
	if (i == 0)
		vector_add(arm, arm_argument_new(av[i], "prog"));
	else if (force_param)
		vector_add(arm, arm_argument_new(av[i], "param"));
	else if (ft_strequ("--", av[i]))
		force_param = true;
	else if (len > 2 && av[i][0] == '-' && av[i][1] == '-')
		vector_add(arm, arm_argument_new(&av[i][2], "opt_alias"));
	else if (len > 1 && av[i][0] == '-')
		add_options(av, i, len, arm);
	else
	{
		vector_add(arm, arm_argument_new(av[i], "param"));
		force_param = true;
	}
	return (force_param);
}

t_vector				*arm_init(int ac, char **av)
{
	t_vector	*arm;
	int			i;
	t_bool		force_param;

	force_param = false;
	arm = vector_new(VECTOR_DEFAULT_CAPACITY);
	i = 0;
	while (i < ac)
	{
		force_param = set_arg(av, i, arm, force_param);
		i++;
	}
	return (arm);
}
