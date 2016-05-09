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

t_vector	*arm_init(int ac, char **av)
{
	t_vector	*arm;
	int			i;
	size_t		j;
	size_t		len;
	t_bool		force_param;

	force_param = false;
	arm = ft_vectnew();
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (i == 0)
			ft_vectadd(arm, arm_argument_new(av[i], "prog"));
		else if (force_param)
			ft_vectadd(arm, arm_argument_new(av[i], "param"));
		else if (ft_strequ("--", av[i]))
			force_param = true;
		else if (len > 2 && av[i][0] == '-' && av[i][1] == '-')
			ft_vectadd(arm, arm_argument_new(&av[i][2], "opt_alias"));
		else if (len > 1 && av[i][0] == '-')
		{
			j = 1;
			while (j < len)
			{
				ft_vectadd(arm, arm_argument_new(ft_strsub(av[i], j, 1),
				"option"));
				j++;
			}
		}
		else
		{
			ft_vectadd(arm, arm_argument_new(av[i], "param"));
			force_param = true;
		}
		i++;
	}
	return (arm);
}
