/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_findoption_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:25:04 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/27 14:36:02 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*opm_findoption_param(t_vector *options, char *name)
{
	t_opm_option	*option;

	option = opm_findoption(options, name);
	if (option && option->param)
		return (option->param);
	return (NULL);
}
