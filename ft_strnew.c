/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:39:01 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/25 11:16:39 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned int	i;

	s = ft_memalloc(size + 1);
	s = ft_memset(s, '\0', size + 1);
	return (s);
}
