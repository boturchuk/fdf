/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboturch <mboturch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 12:09:26 by mboturch          #+#    #+#             */
/*   Updated: 2020/01/21 13:56:23 by mboturch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define BUFF_SIZE 10

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_points
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_points;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

typedef struct		s_map
{
	t_coord			**matrix;
	int				width;
	int				height;
}					t_map;

typedef struct		s_graphics
{
	void			*mlx;
	void			*win;
	t_map			*map;
	double			zoom;
	double			hgt;
	int				sin;
	int				cos;
	int				xm;
	int				ym;
	int				colors[8];
	int				color_index;
	int				def_color;
	int				legend;
}					t_graphics;

t_coord				*get_line(char *str, int size);
void				read_map(t_map **map, int fd, char *file);
void				get_map_info(t_map **map, int fd);
t_map				*get_map(char *file);

void				init_drawing(t_graphics *fdf, int i, int j);
int					draw(t_graphics *fdf);
void				color(t_graphics *fdf);
void				visual(t_graphics *fdf);
void				start_mlx(t_graphics *fdf);

void				legend(t_graphics *fdf);
void				draw_line(t_points pts, t_draw draw, t_graphics *fdf);
void				init_draw_var(t_draw *draw, t_points pts);
void				init_points_right(t_points *pts,
					t_graphics *fdf, int i, int j);
void				init_points_left(t_points *pts,
					t_graphics *fdf, int i, int j);
void				isometric_projection(t_graphics *fdf);

void				rotate(int keycode, t_graphics *fdf);
void				zoom(int keycode, t_graphics *fdf);
void				change_color(t_graphics *fdf);
int					key(int code, t_graphics *fdf);
void				height(int keycode, t_graphics *fdf);

void				ft_error(int msg);
void				free_mem(char ***s);
int					count_num(char *s);

typedef	struct		s_gnl
{
	int				fd;
	char			*rem;
	struct s_gnl	*next;
}					t_gnl;

t_gnl				*newlist(const int fd);
char				*check_rem(char **line, char *rem);
int					get_this_line(const int fd, char **line, char *rem);
int					get_next_line(const int fd, char **line);

#endif
