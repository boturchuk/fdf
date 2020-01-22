/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:40:14 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/21 13:15:10 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points_right(t_points *pts, t_graphics *fdf, int i, int j)
{
	pts->x0 = fdf->map->matrix[i][j].x;
	pts->y0 = fdf->map->matrix[i][j].y;
	pts->x1 = fdf->map->matrix[i][j + 1].x;
	pts->y1 = fdf->map->matrix[i][j + 1].y;
}

void	init_points_left(t_points *pts, t_graphics *fdf, int i, int j)
{
	pts->x0 = fdf->map->matrix[i][j].x;
	pts->y0 = fdf->map->matrix[i][j].y;
	pts->x1 = fdf->map->matrix[i + 1][j].x;
	pts->y1 = fdf->map->matrix[i + 1][j].y;
}

int		count_num(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != ' ')
				s++;
		}
	}
	return (count);
}

void	change_color(t_graphics *fdf)
{
	if (fdf->color_index == 6)
		fdf->color_index = 0;
	else
		fdf->color_index++;
	draw(fdf);
}

void	free_mem(char ***s)
{
	int		i;

	i = 0;
	while (*s[i])
	{
		free(*s[i]);
		i++;
	}
}
