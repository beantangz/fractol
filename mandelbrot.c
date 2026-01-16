/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:54:31 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 17:45:15 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter_mandelbrot(t_env *env, int x, int y, t_complex *z_out)
{
	t_complex	c;
	t_complex	z;
	long double	z_re2;
	long double	z_im2;
	int			i;

	i = 0;
	z.re = 0;
	z.im = 0;
	c = coord_to_complexe(env, x, y);
	while (i < env -> max_iter)
	{
		z_re2 = z.re * z.re;
		z_im2 = z.im * z.im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = z_re2 - z_im2 + c.re;
		i++;
	}
	z_out -> re = z.re;
	z_out -> im = z.im;
	return (i);
}

int	color_mandelbrot(t_env *env, int x, int y)
{
	int			iter;
	t_complex	z;
	long double	smooth;
	double		t;

	iter = iter_mandelbrot(env, x, y, &z);
	if (iter == env -> max_iter)
		return (0x000000);
	smooth = iter + 1.0 - log2(log2(z.re * z.re + z.im * z.im));
	t = smooth / env->max_iter;
	return (
		((int)(9 * (1 - t) * t * t * t * 255) << 16) |
		((int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8) |
		(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)
	);
}

void	draw_mandelbrot(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env -> height)
	{
		x = 0;
		while (x < env -> width)
		{
			my_mlx_pixel_put(env, x, y, (color_mandelbrot(env, x, y)));
			x++;
		}
		y++;
	}
}
