/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:24:39 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/20 12:22:12 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_gnl		*newlist(const int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->rem = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char		*check_rem(char **p_n, char *rem)
{
	char *new_line;

	if ((*p_n = ft_strchr(rem, '\n')) != NULL)
	{
		new_line = ft_strsub(rem, 0, *p_n - rem);
		ft_strcpy(rem, ++(*p_n));
	}
	else
	{
		new_line = ft_strnew(ft_strlen(rem) + 1);
		ft_strcat(new_line, rem);
		ft_strclr(rem);
	}
	return (new_line);
}

int			get_this_line(const int fd, char **line, char *rem)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				bwr;

	p_n = NULL;
	bwr = 1;
	*line = check_rem(&p_n, rem);
	while (p_n == NULL && ((bwr = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[bwr] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rem, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || bwr < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rem) || bwr) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	if (head == NULL)
		head = newlist(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	return (get_this_line(fd, line, tmp->rem));
}
