/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_totab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:26:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/24 16:26:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**vector_totab(t_vector *this)
{
	char			**tab;
	int				i;

	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * this->total + 1)))
		return (NULL);
	while (i < this->total)
	{
		tab[i] = ft_strdup(this->items[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
