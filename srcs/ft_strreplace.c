/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:33:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 14:00:21 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strreplace(const char *str, const char *to, char *by)
{
	int			begin;
	int			to_len;
	char		*found;
	char		*s;

	found = ft_strstr(str, to);
	if (!found)
		return (NULL);
	to_len = ft_strlen(to);
	begin = ft_strindex(str, to);
	s = ft_strnew(ft_strlen(str) - to_len + ft_strlen(by));
	ft_strncpy(s, str, begin);
	ft_putendl(s);
	ft_strcat(s, by);
	ft_putendl(s);
	ft_strcat(s, &str[begin + to_len]);
	ft_putendl(s);
	return (s);
}
