/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:29:45 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 17:48:25 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_view(t_env *env, long double dx, long double dy)
{
	env -> min_re += dx;
	env -> max_re += dx;
	env -> min_im += dy;
	env -> max_im += dy;
}

void	handle_arrow_keys(int keycode, t_env *env)
{
	long double	step;

	step = (env->max_re - env->min_re) * 0.1;
	if (keycode == 65361)
		move_view(env, -step, 0);
	else if (keycode == 65363)
		move_view(env, step, 0);
	else if (keycode == 65362)
		move_view(env, 0, step);
	else if (keycode == 65364)
		move_view(env, 0, -step);
}

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 65307)
		close_window(env);
	if (keycode == 69)
		env -> max_iter += 50000;
	handle_arrow_keys(keycode, env);
	env -> need_redraw = 1;
	return (0);
}

void	z(t_env *env, long double ce, long double ci, long double zoom)
{
	long double	re_range;
	long double	im_range;

	re_range = (env->max_re - env->min_re) * zoom;
	im_range = (env->max_im - env->min_im) * zoom;
	env -> min_re = ce - re_range / 2;
	env -> max_re = ce + re_range / 2;
	env -> min_im = ci - im_range / 2;
	env -> max_im = ci + im_range / 2;
}

int	mouse_handler(int button, int x, int y, t_env *env)
{
	long double	zoom_factor;
	long double	zoom;
	t_complex	zz;

	zoom_factor = 0.9;
	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
		zoom = pow(zoom_factor, 1);
	else
		zoom = pow(1.0 / zoom_factor, 1);
	zz = coord_to_complexe(env, x, y);
	z(env, zz.re, zz.im, zoom);
	env -> need_redraw = 1;
	return (0);
}
