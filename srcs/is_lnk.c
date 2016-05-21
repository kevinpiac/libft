/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lnk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:33:43 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/25 14:00:21 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			is_lnk(const char *path)
{
	struct stat	*stat;

	stat = (struct stat *)ft_memalloc(sizeof(struct stat) * 1);
	lstat(path, stat);
	return (S_ISLNK(stat->st_mode));
}
