/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:26:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/24 16:26:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_delsplit(char **splited)
{
	int			i;

	i = 0;
	if (splited)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		splited[i] = NULL;
		i++;
	}
	free(splited);
}
