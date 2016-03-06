/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsetfour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 18:28:04 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/06 11:03:09 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitsetfour(int *i, int val, unsigned int index)
{
	int		n;

	n = *i;
	n &= ~(15 << index * 4);
	n |= (val << index * 4);
	*i = n;
}
