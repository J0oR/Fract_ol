/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_mappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:28:54 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/31 18:28:56 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_mandelbrot_n(int x, int y, t_data data)
{
	double tmp;
	double zr;
	double zi;
	double cr;
	double ci;

	zr = 0.0;
	zi = 0.0;
	cr = 1.5 * (x + data.uty.move_x - data.win_w / 1.8) /
			(0.5 * data.win_w * data.uty.zoom);
	ci = (y + data.uty.move_y - data.win_h / 2) /
			(0.5 * data.win_h * data.uty.zoom);
	while (data.it++ < data.max_it && (zr * zr + zi * zi) < 4.0)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
	}
	return (data.it);
}

int		ft_julia_n(int x, int y, t_data data)
{
	double z_r;
	double z_i;
	double tmp;

	z_r = 1.5 * (x + data.uty.move_x - data.win_w / 2) /
			(0.5 * data.win_w * data.uty.zoom);
	z_i = (y + data.uty.move_y - data.win_h / 2) /
			(0.5 * data.win_h * data.uty.zoom);
	while (data.it++ < data.max_it && (z_r * z_r + z_i * z_i) < 4.0)
	{
		tmp = z_r * z_r - z_i * z_i + data.julia_r;
		z_i = 2 * z_r * z_i + data.julia_i;
		z_r = tmp;
	}
	return (data.it);
}

int		ft_newton_n(int x, int y, t_data data)
{
	double	tmp;
	double	z_r;
	double	z_i;
	double	tmp_r;
	double	tmp_i;

	z_r = 1.5 * (x + data.uty.move_x - data.win_w / 2) /
			(0.5 * data.win_w * data.uty.zoom);
	z_i = (y + data.uty.move_y - data.win_h / 2) /
			(0.5 * data.win_h * data.uty.zoom);
	tmp = 1.0;
	while (data.it++ < data.max_it && tmp > 0.000001)
	{
		tmp_r = z_r;
		tmp_i = z_i;
		tmp = (z_r * z_r + z_i * z_i) * (z_r * z_r + z_i * z_i);
		z_r = (2 * z_r * tmp + z_r * z_r - z_i * z_i) / (3.0 * tmp);
		z_i = (2 * z_i * (tmp - tmp_r)) / (3.0 * tmp);
		tmp = (z_r - tmp_r) * (z_r - tmp_r) + (z_i - tmp_i) * (z_i - tmp_i);
	}
	return (data.it);
}

int		ft_burning_ship_n(int xx, int yy, t_data data)
{
	double tmp;
	double x0;
	double y0;
	double x;
	double y;

	x0 = 2.0 * (xx + data.uty.move_x - data.win_w / 2) /
			(0.5 * data.win_w * data.uty.zoom);
	y0 = (yy + data.uty.move_y - data.win_h / 1.7) /
			(0.5 * data.win_h * data.uty.zoom);
	x = 0.0;
	y = 0.0;
	while ((x * x + y * y) < 4 && data.it++ < data.max_it)
	{
		tmp = x * x - y * y + x0;
		y = fabs(2 * x * y + y0);
		x = fabs(tmp);
	}
	return (data.it);
}
