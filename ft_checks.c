/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:57:50 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/18 18:57:52 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_print_options(void)
{
	ft_putendl("Please, type farctal's corresponding number from the list:");
	ft_putendl("1) Mandelbrot");
	ft_putendl("2) Julia");
	ft_putendl("3) Newton");
	ft_putendl("4) Burning Ship");
	return (1);
}

int		ft_f_selector(char **av, t_opt *opts, t_data *data)
{
	if (ft_strcmp(av[1], "1") == 0)
	{
		opts->fract_ft = &ft_mandelbrot_n;
		data->fract = 1;
	}
	if (ft_strcmp(av[1], "2") == 0)
	{
		opts->fract_ft = &ft_julia_n;
		data->fract = 2;
	}
	if (ft_strcmp(av[1], "3") == 0)
	{
		opts->fract_ft = &ft_newton_n;
		data->fract = 3;
	}
	if (ft_strcmp(av[1], "4") == 0)
	{
		opts->fract_ft = &ft_burning_ship_n;
		data->fract = 4;
	}
	if (!opts->fract_ft)
		return (ft_print_options());
	return (0);
}

int		ft_checks(t_data *data, int ac, char **av, t_opt *opts)
{
	if (ac != 2)
	{
		ft_print_options();
		return (1);
	}
	if (ft_f_selector(av, opts, data))
		return (1);
	if (!(data->ptr = mlx_init()))
		return (1);
	if (!(data->win = mlx_new_window(data->ptr, data->win_w, \
	data->win_h, av[1])))
		return (1);
	if (!(data->img.img_ptr = mlx_new_image(data->ptr, data->win_w, \
	data->win_h)))
		return (1);
	if (!(data->img.data = (int*)mlx_get_data_addr(data->img.img_ptr, \
	&data->img.bpp, &data->img.size_l, &data->img.endian)))
		return (1);
	return (0);
}
