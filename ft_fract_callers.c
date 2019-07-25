/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_callers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruocco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:27:00 by gruocco           #+#    #+#             */
/*   Updated: 2018/01/31 18:27:01 by gruocco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	*ft_it_n_caller(void *arg)
{
	int		n;
	int		y;
	int		rgb;
	t_xy	*pix;

	pix = (t_xy *)arg;
	y = -1;
	while (++y < pix->data->win_h)
	{
		n = pix->f_n(pix->x, y, *pix->data);
		rgb = n % 156 * pix->data->color + n % 156 * 1000;
		pix->data->img.data[pix->x + y * pix->data->win_w] = rgb;
	}
	pthread_exit(NULL);
}

void	ft_row(t_data *data, int (*f_n) (int, int, t_data))
{
	int				x;
	pthread_t		threads_id[data->win_w];
	t_xy			thread_arg[data->win_w];

	x = -1;
	while (++x < data->win_w)
	{
		thread_arg[x].x = x;
		thread_arg[x].data = data;
		thread_arg[x].f_n = *f_n;
	}
	x = -1;
	while (++x < data->win_w)
		pthread_create(&threads_id[x], NULL, \
		&ft_it_n_caller, (void *)&thread_arg[x]);
	x = -1;
	while (++x < data->win_w)
		pthread_join(threads_id[x], NULL);
}
