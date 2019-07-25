/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:26:34 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/31 18:26:36 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	param_filler(t_data *data)
{
	data->win_w = 1200;
	data->win_h = 900;
	data->uty.zoom = 0.5;
	data->uty.move_y = 0;
	data->uty.move_x = 0;
	data->it = 0;
	data->max_it = 200;
	data->julia_r = -0.7;
	data->julia_i = 0.27015;
	data->julia_mouse_flag = 0;
	data->calc_flag = 0;
	data->drawed = 0;
	data->mouse_flag = 0;
	data->color = 1000;
}

int		ft_calc(t_data *data)
{
	int (*(param)) (int, int, t_data);

	if (data->fract == 1)
		param = &ft_mandelbrot_n;
	else if (data->fract == 2)
		param = &ft_julia_n;
	else if (data->fract == 3)
		param = &ft_newton_n;
	else
		param = &ft_burning_ship_n;
	ft_row(data, param);
	data->calc_flag = 1;
	return (0);
}

int		ft_draw(void *dt)
{
	t_data *data;

	data = (t_data *)dt;
	if (data->calc_flag == 0)
	{
		ft_calc(data);
		data->drawed = 0;
	}
	if (data->drawed == 0)
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.img_ptr, 0, 0);
		data->drawed = 1;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;
	t_opt	opts;

	opts.fract_ft = NULL;
	param_filler(&data);
	if (ft_checks(&data, ac, av, &opts))
		return (0);
	mlx_key_hook(data.win, ft_keys, &data);
	mlx_mouse_hook(data.win, ft_mouse_zoom, &data);
	mlx_hook(data.win, 6, 1L << 6, ft_mouse_hook, &data);
	mlx_loop_hook(data.ptr, &ft_draw, &data);
	mlx_loop(data.ptr);
	return (0);
}
