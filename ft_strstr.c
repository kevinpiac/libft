/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:44:42 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 09:41:18 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!little || *little == '\0')
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j])
		{
			if (!little[j + 1])
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}








