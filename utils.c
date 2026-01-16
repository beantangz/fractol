/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:34:14 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 22:25:37 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_env *data, int x, int y, int color)
{
	char	*dst;

	dst = data -> addr + (y * data -> line_len + x * (data -> bpp / 8));
	*(unsigned int *)dst = color;
}

t_complex	coord_to_complexe(t_env *env, int x, int y)
{
	t_complex	z;

	z.re = env->min_re + x * (env->max_re - env->min_re) / env->width;
	z.im = env->max_im - y * (env->max_im - env->min_im) / env->height;
	return (z);
}

int	close_window(t_env	*img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	exit(0);
	return (0);
}

int	refresh_image(t_env *e)
{
	if (!e -> need_redraw)
		return (0);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->line_len, &e->endian);
	if (e -> fractal_type == 0)
		draw_mandelbrot(e);
	else if (e -> fractal_type == 1)
		draw_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	e -> need_redraw = 0;
	return (0);
}
