/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_issetoption.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:01:07 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/26 15:34:29 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	opm_issetoption(t_vector *options, char *name)
{
	t_opm_option	*option;

	option = opm_findoption(options, name);
	if (option && option->is_set)
		return (true);
	return (false);
}
