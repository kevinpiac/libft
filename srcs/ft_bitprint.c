/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:16:59 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/06 11:26:46 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitprint(unsigned int i)
{
	int	j;

	j = 31;
	while (j >= 0)
	{
		if (j != 31 && !((j + 1) % 4))
			ft_putchar(' ');
		ft_putnbr(1 & (i >> j--));
	}
	ft_putchar('\n');
}