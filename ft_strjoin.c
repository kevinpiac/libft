/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:23:04 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 17:00:51 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	size_t	len1;

	len1 = ft_strlen(s1);
	if (!(s = ft_memalloc(len1 + ft_strlen(s2))))
		return (NULL);
	s = strcpy(s, s1);
	printf("S -> %s\n", s);
	s = ft_strcat(s, s2);
	return (s);
}
