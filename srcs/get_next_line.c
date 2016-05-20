/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:44:47 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/04 14:35:23 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*gnl_setrest(char *buf, int ret, int fd, t_gnl **lst)
{
	t_gnl		*elem;
	char		*cp;

	elem = *lst;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (!elem && ret)
	{
		elem = (t_gnl *)ft_lstnew(buf, (size_t)ret + 1);
		elem->fd = fd;
		ft_lstadd((t_list **)lst, (t_list *)elem);
	}
	else if (elem && ret)
	{
		cp = ft_strjoin(elem->content, buf);
		free(elem->content);
		elem->content = ft_strdup(cp);
		free(cp);
	}
	return (elem);
}

static int		gnl_getline(t_gnl *rest, char **line, int ret)
{
	char		*after_lfeed;
	char		*old_rest;
	char		*new_rest;
	size_t		len;

	len = 0;
	if ((after_lfeed = ft_strchr(rest->content, '\n')))
	{
		old_rest = rest->content;
		while (old_rest[len] != '\n')
			len++;
		*line = ft_strsub(old_rest, 0, len);
		new_rest = ft_strdup(++after_lfeed);
		rest->content = new_rest;
		free(old_rest);
		return (1);
	}
	if (!ret && rest && rest->content)
	{
		*line = ft_strdup(rest->content);
		ft_memdel(&(rest)->content);
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*rest;
	char			buf[GNL_BUFF_SIZE + 1];
	int				ret;

	if (fd == -1)
		return (-1);
	ret = read(fd, buf, GNL_BUFF_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	rest = gnl_setrest(buf, ret, fd, &lst);
	if (rest && rest->content && ft_strlen(rest->content))
	{
		if (gnl_getline(rest, line, ret))
			return (1);
		return (get_next_line(fd, line));
	}
	else
		return (0);
}
