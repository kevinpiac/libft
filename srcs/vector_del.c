/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 14:20:56 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 14:21:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			vector_del(t_vector *this, void (*del_fn)(void *))
{
	vector_clear(this, del_fn);
	if (this->items)
		free(this->items);
	free(this);
}
