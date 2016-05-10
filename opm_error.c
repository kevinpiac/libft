/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:55:06 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/28 14:44:23 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			opm_error(void)
{
	ft_putendl_fd(OPM_ERROR_MSG, 2);
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(OPM_PROGNAME, 2);
	ft_putstr_fd(" ", 2);
	ft_putendl_fd(OPM_USAGE, 2);
	exit(-1);
}
