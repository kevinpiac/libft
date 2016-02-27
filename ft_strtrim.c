/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:48:57 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 17:56:12 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	size_t			len;
	size_t			less;

	i = 0;
	j = 0;
	len = 0;
	less = 0;
	while (ft_istoskip(" \n\t", s[i]))
		i++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strcpy(str, &s[i]);
	i = 0;
	return (str);
}
