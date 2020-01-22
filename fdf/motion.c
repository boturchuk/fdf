/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:20:00 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/21 13:51:11 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key(int code, t_graphics *fdf)
{
	if (code == 53)
		exit(0);
	if (code == 6)
		change_color(fdf);
	if (code == 4 || code == 38)
		height(code, fdf);
	if (code == 69 || code == 78)
		zoom(code, fdf);
	if (code == 126 || code == 125 ||
		code == 124 || code == 123)
		rotate(code, fdf);
	return (0);
}

void	height(int code, t_graphics *fdf)
{
	if (code == 38)
		fdf->hgt -= 0.05;
	if (code == 4)
		fdf->hgt += 0.05;
	draw(fdf);
}

void	zoom(int code, t_graphics *fdf)
{
	if (code == 78)
	{
		if (fdf->zoom > 0.1)
			fdf->zoom -= 0.1;
	}
	if (code == 69)
	{
		if (fdf->zoom < 3)
			fdf->zoom += 0.1;
	}
	draw(fdf);
}

void	rotate(int code, t_graphics *fdf)
{
	if (code == 123)
		fdf->cos -= 7;
	if (code == 124)
		fdf->cos += 7;
	if (code == 126)
		fdf->sin += 7;
	if (code == 125)
		fdf->sin -= 7;
	draw(fdf);
}
