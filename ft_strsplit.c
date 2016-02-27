/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:19:21 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 16:34:55 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_wordcnt(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && i > 0 && s[i - 1] != c)
			count++;
		i++;
	}
}

static size_t		ft_wordlen(char const *s, char c)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char			*ft_getword(char const *s, char c)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	while (s[i] == c)
		i++;
	len = ft_wordlen(s[i], c);
	if (!(str = (char *)ft_strnew(sizeof(char) * len)))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;
	char			**tab;

	count = ft_wordcnt(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * count + 1)))
		return (NULL);
	i = 0;
	while (count--)
	{
		ft_getword(s[count--], c);
	}
	char **st;
	*st = "coucou";
	return (st);
}
