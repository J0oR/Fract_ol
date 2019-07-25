/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:49:04 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/20 21:49:05 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_zoom_move(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		if ((x > data->win_w / 2) && x != data->mouse_x)
			data->uty.move_x += (x - data->win_w / 2) / 2;
		if ((x <= data->win_w / 2) && x != data->mouse_x)
			data->uty.move_x += -(data->win_w / 2 - x) / 2;
		if ((y > data->win_h / 2) && y != data->mouse_y)
			data->uty.move_y += (y - data->win_h / 2) / 2;
		if ((y <= data->win_h / 2) && y != data->mouse_y)
			data->uty.move_y += -(data->win_h / 2 - y) / 2;
	}
}

int		ft_mouse_zoom(int button, int x, int y, t_data *data)
{
	/*if (data->mouse_flag == 0)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		data->mouse_flag = 1;
		return (0);
	}*/
	(void)x;
	(void)y;
	if (button == 5 || button == 4)//&& data->mouse_flag == 1)
	{
		if (button == 5)
			data->uty.zoom += 0.5;
		if (button == 4 && (data->uty.zoom) > 0.05)
			data->uty.zoom += -(0.05);
		//ft_zoom_move(button, x, y, data);
	//	data->mouse_x = x;
		//data->mouse_y = y;
		data->calc_flag = 0;
	}
	return (0);
}

int		ft_mouse_hook(int x, int y, t_data *data)
{
	if (data->julia_mouse_flag == 0 && data->fract == 2)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		data->julia_mouse_flag = 1;
		return (0);
	}
	if ((x != data->mouse_x || y != data->mouse_y) && data->fract == 2)
	{
		if ((x > data->mouse_x) && ((x - data->mouse_x) >= 15))
			data->julia_r += 0.06;
		else if ((x < data->mouse_x) && ((data->mouse_x - x) >= 15))
			data->julia_r += -(0.06);
		if ((y > data->mouse_y) && ((y - data->mouse_y) >= 15))
			data->julia_i += 0.06;
		else if ((y < data->mouse_y) && ((data->mouse_y - y) >= 15))
			data->julia_i += -(0.06);
		data->mouse_x = x;
		data->mouse_y = y;
		data->calc_flag = 0;
	}
	return (0);
}

void	ft_color(int keycode, t_data *data)
{
	if (keycode == 18)
		data->color = 10000;
	else if (keycode == 19)
		data->color = 20000;
	else if (keycode == 20)
		data->color = 1000000;
	else if (keycode == 21)
		data->color = 2000000;
	else
		data->color = 1000;
	data->calc_flag = 0;
}

int		ft_keys(int keycode, t_data *data)
{
	if (keycode == 18 || keycode == 19 || keycode == 20
		|| keycode == 21 || keycode == 23)
		ft_color(keycode, data);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		if (keycode == 126)
			data->uty.move_y += 50;
		else if (keycode == 125)
			data->uty.move_y += -50;
		else if (keycode == 123)
			data->uty.move_x += 50;
		else
			data->uty.move_x += -50;
		data->calc_flag = 0;
	}
	if (keycode == 53)
	{
		mlx_destroy_image(data->ptr, data->img.img_ptr);
		mlx_destroy_window(data->ptr, data->win);
		exit(0);
	}
	return (0);
}
