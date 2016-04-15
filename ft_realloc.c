/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 22:05:34 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 09:38:55 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t newsize)
{
	void	*new;

	if (!(new = ft_memalloc(sizeof(void *) * newsize)))
		return (NULL);
	if (newsize < size)
		size = newsize;
	if (ptr != NULL)
	{
		(void)ft_memcpy(new, ptr, size);
		free(ptr);
	}
	return (new);
}
