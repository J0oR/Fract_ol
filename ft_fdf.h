/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:14:30 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 18:14:32 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <pthread.h>

typedef struct	s_utils
{
	int		move_x;
	int		move_y;
	double	zoom;
}				t_utils;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*ptr;
	void		*win;
	t_img		img;
	t_utils		uty;
	int			max_it;
	int			it;
	double		julia_r;
	double		julia_i;
	int			mouse_x;
	int			mouse_y;
	int			fract;
	int			win_w;
	int			win_h;
	int			julia_mouse_flag;
	int			calc_flag;
	int			drawed;
	int			mouse_flag;
	int			color;
}				t_data;

typedef struct	s_xy
{
	int		x;
	t_data	*data;
	int		(*(f_n)) (int, int, t_data);
}				t_xy;

typedef struct	s_opt
{
	int (*(fract_ft)) (int, int, t_data);
}				t_opt;

int				ft_mandelbrot_n (int x, int y, t_data data);
int				ft_julia_n (int x, int y, t_data data);
int				ft_newton_n (int x, int y, t_data data);
int				ft_burning_ship_n (int x, int y, t_data data);

void			*ft_it_n_caller(void *arg);
void			ft_row(t_data *data, int (*f_n) (int, int, t_data));

int				ft_mouse_hook(int x, int y, t_data *data);
int				ft_mouse_zoom(int button, int x, int y, t_data *data);
int				ft_keys(int keycode, t_data *data);

int				ft_checks(t_data *data, int ac, char **av, t_opt *opts);
#endif
