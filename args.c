/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:57:38 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 17:22:58 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tcheck_param(int ac, char **av, t_env *img)
{
	if (ac == 1 || tcheck_av(ac, av, img) != 0)
	{
		ft_printf("mandelbrot\njulia param (1 or 2)\n");
		return (1);
	}
	if (ac == 3 && param_julia_tchek(av) != 0)
	{
		ft_printf("wrong julia param, choices are : 1 or 2\n");
		return (1);
	}
	return (0);
}

int	tcheck_av(int ac, char **av, t_env *img)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		img -> fractal_type = 0;
		return (0);
	}
	if (ac == 3 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		if (ft_strncmp(av[2], "1", 2) == 0)
		{
			img -> im = 0;
			img -> re = 0.3;
		}
		else if (ft_strncmp(av[2], "2", 2) == 0)
		{
			img -> im = 0.7;
			img -> re = -0.2;
		}
		img -> fractal_type = 1;
		return (0);
	}
	return (1);
}

void	init_img(t_env *img)
{
	long double	temp;

	temp = (long double)img->height / (long double)img->width;
	img -> max_iter = 100;
	img -> min_re = -2.0;
	img -> max_re = 1.0;
	img -> min_im = -1.2;
	img -> max_im = img -> min_im + (img -> max_re - img -> min_re) * temp;
}

int	param_julia_tchek(char **av)
{
	if (ft_strncmp(av[2], "1", 2) == 0)
		return (0);
	if (ft_strncmp(av[2], "2", 2) == 0)
		return (0);
	return (1);
}
