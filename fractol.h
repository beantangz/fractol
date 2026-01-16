/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:50 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 17:36:52 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_env	t_env;
struct s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	long double	min_re;
	long double	max_re;
	long double	min_im;
	long double	max_im;
	int			max_iter;
	int			width;
	int			height;
	int			need_redraw;
	int			fractal_type;
	long double	re;
	long double	im;
};

typedef struct s_complex
{
	long double	re;
	long double	im;
}	t_complex;

void		my_mlx_pixel_put(t_env *data, int x, int y, int color);
int			close_window(t_env	*current);
t_complex	coord_to_complexe(t_env *env, int x, int y);
int			color_mandelbrot(t_env *env, int x, int y);
void		draw_mandelbrot(t_env *env);
void		move_view(t_env *env, long double dx, long double dy);
void		handle_arrow_keys(int keycode, t_env *env);
int			key_handler(int keycode, t_env *env);
void		z(t_env *env, long double r, long double i, long double z);
int			mouse_handler(int button, int x, int y, t_env *env);
int			refresh_image(t_env *env);
void		init_img(t_env *img);
int			tcheck_param(int ac, char **av, t_env *img);
int			tcheck_av(int ac, char **av, t_env *img);
int			color_julia(t_env *env, int x, int y);
void		draw_julia(t_env *env);
int			refresh_image1(t_env *env);
int			param_julia_tchek(char **av);

#endif