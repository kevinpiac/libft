/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:19:21 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/29 19:04:08 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	wordcount(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (i == 0 || *(s - 1) == c))
			i++;
		s++;
	}
	return (i);
}

static size_t	wordlen(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**tabcpy;
	size_t	len;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * wordcount(s, c))))
		return (NULL);
	tabcpy = tab;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = wordlen(s, c);
			if (!(*tabcpy = ft_strnew(len)))
				return (NULL);
			strncpy(*tabcpy, s, len);
//			printf("copying %s with len = %d\n", s, len);
			s = (s + len);
			tabcpy++;
		}
	}
	free(tabcpy);
	return (tab);
}
