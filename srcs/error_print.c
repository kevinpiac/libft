/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:26:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/24 16:26:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				error_print(int error_type, char *cmd, char *error_details)
{
	ft_putendl_fd(ERROR_DEFAULT_MSG, 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error_details)
		ft_putendl_fd(error_details, 2);
	else if (error_type == 1)
		ft_putendl_fd("command not found", 2);
	else if (error_type == 2)
		ft_putendl_fd("file or directory unsaccesible", 2);
	else if (error_type == 3)
		ft_putendl_fd("invalid parameter, RTFM!", 2);
	else if (error_type == 4)
	{
		ft_putendl_fd("invalid parameter", 2);
		ft_putendl_fd(ERROR_USAGE, 2);
	}
	else
		ft_putendl_fd("an error occured", 2);
}
