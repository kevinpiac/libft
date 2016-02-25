/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:42:48 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/25 11:31:19 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strstr (const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!little)
		return (big);
	while (big[i])
	{
		while (big[i] == little[j])
		{

		}
		i++;
	}
}

abjejdeckjewhlqwejhleqwkdhj
