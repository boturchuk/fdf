/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:10:29 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/21 13:23:02 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	legend(t_graphics *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 3, 30, 250, " Rotate: UP, \
			RIGHT, DOWN, LEFT");
	mlx_string_put(fdf->mlx, fdf->win, 3, 120, 250, " Color: Z");
	mlx_string_put(fdf->mlx, fdf->win, 3, 90, 250, " Height: H, J");
	mlx_string_put(fdf->mlx, fdf->win, 3, 60, 250, " Zoom: +, -");
	mlx_string_put(fdf->mlx, fdf->win, 3, 150, 250, " Exit: ESC");
}

void	color(t_graphics *fdf)
{
	if (fdf->def_color)
		fdf->colors[0] = fdf->def_color;
	else
	{
		fdf->colors[0] = 0xFF3399;
		fdf->colors[1] = 0xBBFAFF;
		fdf->colors[2] = 0x9900FF;
		fdf->colors[3] = 0x00FF00;
		fdf->colors[4] = 0xfc0345;
		fdf->colors[5] = 0x000000;
		fdf->colors[6] = 0x00FFFF;
	}
}

void	visual(t_graphics *fdf)
{
	fdf->zoom = 0.5;
	fdf->hgt = 0.2;
	fdf->sin = 45;
	fdf->cos = 35;
	fdf->xm = 0;
	fdf->ym = 0;
	fdf->color_index = 0;
	fdf->legend = 2;
	color(fdf);
}

void	start_mlx(t_graphics *fdf)
{
	visual(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "FDF");
	mlx_expose_hook(fdf->win, draw, fdf);
	mlx_key_hook(fdf->win, key, fdf);
	mlx_loop(fdf->mlx);
}
