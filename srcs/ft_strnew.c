/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:39:01 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/13 19:06:32 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;

	if (!(s = ft_memalloc(size + 1)))
		return (NULL);
	s = ft_memset(s, '\0', size + 1);
	return (s);
}
