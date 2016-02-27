/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:20:15 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 16:10:56 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	toskip(const int c)
{
	char tab[] = "\n\r\t\v\f ";
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi(const char *s)
{
	int				sign;
	int				res;
	unsigned int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (toskip(s[i]))
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}
