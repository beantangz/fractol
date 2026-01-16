/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:59:52 by mleineku          #+#    #+#             */
/*   Updated: 2025/06/29 22:14:00 by mleineku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_env	img;

	ft_bzero(&img, sizeof(t_env));
	if (tcheck_param(ac, av, &img) != 0)
		return (0);
	img.width = 1920;
	img.height = 1080;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "fractale");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	init_img(&img);
	mlx_key_hook(img.win, key_handler, &img);
	mlx_mouse_hook(img.win, mouse_handler, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop_hook(img.mlx, refresh_image, &img);
	mlx_loop(img.mlx);
	return (0);
}
