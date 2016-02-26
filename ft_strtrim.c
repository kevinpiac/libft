/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:48:57 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/26 13:38:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	j = 0;
	len = 0;
	while (s[++i])
		ft_isspace(s[i]) ? 0 : len++;
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[len] = '\0';
	return (str);
}
