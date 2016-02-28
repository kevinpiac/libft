/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:20:52 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/28 18:37:29 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = ft_strlen(s1);
	s2 + i;
	while (*s2 && n)
		*s1++ = *s2++;
	s1 = '\0';
	return (i + n);
}
