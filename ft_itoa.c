/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:42:54 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 17:21:32 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	len;
	int				tmp;
	int				neg;
	char			*res;

	tmp = n;
	len = 1;
	neg = 0;
	n >= 0 ? 0 : (neg = 1);
	if (n == -2147483648)
		return ("-2147483648");
	while (tmp /= 10)
		len++;
	res = ft_strnew(len + 1 + neg);
	if (neg)
		res[0] = '-';
	while (len--)
	{
		res[len + neg] = ABS(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
