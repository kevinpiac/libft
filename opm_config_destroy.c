/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_config_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:26:29 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/24 16:26:31 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		opm_config_destroy_item(void *item)
{
	t_opm_option *	this;
	int				i;

	i = 0;
	this = (t_opm_option *)item;
	if (!this)
		return ;
	if (this->aliases)
	{
		while (this->aliases[i])
		{
			free(this->aliases[i]);
			i++;
		}
//		free(this->aliases);
	}
	if (this->name)
		free(this->name);
	free(this);
	this = NULL;
}

void			opm_config_destroy(t_vector *this)
{
	if (!this)
		return ;
	ft_vectdel(this, &opm_config_destroy_item);
}
