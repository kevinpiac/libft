/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 22:54:44 by kevin             #+#    #+#             */
/*   Updated: 2016/02/27 09:57:14 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!little || *little == '\0')
		return ((char *)big);
	while (big[i] && n--)
	{
		while (big[i + j] == little[j] && n - j)
		{
			if (!little[j + 1])
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
