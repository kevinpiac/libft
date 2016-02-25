/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:37:33 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/25 14:42:02 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			len;

	len = ft_strlen(s1);
	s2 = ft_memalloc(len + 1);
	s2[len] = '\0';
	while (len--)
		s2[len] = s1[len];
	return (s2);
}
