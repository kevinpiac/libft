/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:06:24 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/04 12:11:28 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strmcp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] && n)
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
