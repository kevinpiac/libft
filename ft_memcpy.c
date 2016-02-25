/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:22:35 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/25 18:50:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst)
		return (NULL);
	while (n--)
		*((char *)dst + n) = *((char *)src + n);
	return (dst);
}
