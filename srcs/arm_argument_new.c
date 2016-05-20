/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm_argument_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:33:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 14:00:21 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arm_argument		*arm_argument_new(char *name, char *type)
{
	t_arm_argument	*argument;

	argument = (t_arm_argument *)ft_memalloc(sizeof(t_arm_argument) * 1);
	argument->name = name;
	argument->type = type;
	return (argument);
}
