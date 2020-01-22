/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:38:33 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/20 17:02:46 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_graphics	fdf;

	if (argc != 2)
		ft_error(0);
	else
	{
		fdf.def_color = 0;
		fdf.map = get_map(argv[1]);
		start_mlx(&fdf);
	}
	return (0);
}
