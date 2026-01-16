/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:38:08 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 17:48:41 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter_julia(t_env *env, int x, int y, t_complex *z)
{
	t_complex	zz;
	long double	z_re2;
	long double	z_im2;
	int			i;

	i = 0;
	zz.re = 0;
	zz.im = 0;
	zz = coord_to_complexe(env, x, y);
	while (i < env -> max_iter)
	{
		z_re2 = zz.re * zz.re;
		z_im2 = zz.im * zz.im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		zz.im = 2.0 * zz.re * zz.im + env -> im;
		zz.re = z_re2 - z_im2 + env -> re;
		i++;
	}
	z -> re = zz.re;
	z -> im = zz.im;
	return (i);
}

int	color_julia(t_env *env, int x, int y)
{
	int			iter;
	t_complex	z;
	long double	smooth;
	double		t;

	iter = iter_julia(env, x, y, &z);
	if (iter == env->max_iter)
		return (0x000000);
	smooth = iter + 1.0 - log2(log2(z.re * z.re + z.im * z.im));
	t = smooth / env->max_iter;
	return (
		((int)(9 * (1 - t) * t * t * t * 255) << 16) |
		((int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8) |
		(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)
	);
}

void	draw_julia(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			my_mlx_pixel_put(env, x, y, color_julia(env, x, y));
			x++;
		}
		y++;
	}
}
