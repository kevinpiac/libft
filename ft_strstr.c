/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:44:42 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/03 17:26:33 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *bigcp;
	const char *littlecp;

	if (!ft_strlen(little) || !little)
		return ((char *)big);
	while (*big)
	{
		bigcp = big;
		littlecp = little;
		while (*bigcp == *littlecp)
		{
			bigcp++;
			littlecp++;
			if (!*littlecp)
				return ((char *)big);

		}
		big++;
	}
	return (NULL);
}
