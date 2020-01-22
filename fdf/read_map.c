/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:32:28 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/21 13:52:17 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*get_line(char *str, int size)
{
	int		i;
	t_coord	*tab;
	char	**temp;

	i = 0;
	tab = (t_coord*)malloc(sizeof(tab) * size * 2);
	temp = ft_strsplit(str, ' ');
	while (temp[i])
	{
		tab[i].x = 0;
		tab[i].y = 0;
		tab[i].z = ft_atoi(temp[i]);
		i++;
	}
	free_mem(&temp);
	return (tab);
}

void		get_map_info(t_map **map, int fd)
{
	int		height;
	int		width;
	int		temp;
	char	*line;

	height = 0;
	width = 0;
	temp = 0;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			ft_error(1);
		if (height == 0)
			width = count_num(line);
		temp = count_num(line);
		if (width != temp)
			ft_error(0);
		height++;
	}
	free(line);
	if (height == 0)
		ft_error(0);
	(*map)->height = height;
	(*map)->width = width;
	close(fd);
}

void		read_map(t_map **map, int fd, char *file)
{
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!((*map)->matrix = (t_coord**)malloc(sizeof(t_coord*)
	* (*map)->height)))
		return ;
	while (get_next_line(fd, &line))
	{
		(*map)->matrix[i] = get_line(line, (*map)->width);
		i++;
	}
	close(fd);
}

t_map		*get_map(char *file)
{
	int		fd;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(1);
	get_map_info(&map, fd);
	read_map(&map, fd, file);
	return (map);
}
