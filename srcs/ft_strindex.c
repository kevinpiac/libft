/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:33:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 14:00:21 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strindex(const char *big, const char *little)
{
	const char			*bigcp;
	const char			*littlecp;
	int					i;

	i = 0;
	if (!ft_strlen(little) || !little)
		return (i);
	while (*big)
	{
		bigcp = big;
		littlecp = little;
		while (*bigcp == *littlecp)
		{
			bigcp++;
			littlecp++;
			if (!*littlecp)
				return (i);
		}
		big++;
		i++;
	}
	return (i);
}
