/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:37:58 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/05 23:18:00 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void	inis(t_mlx *c_mlx)
{
	c_mlx->i = 0;
	c_mlx->j = 0;
	c_mlx->a = 0;
	c_mlx->pos_x = 0;
	c_mlx->pos_y = 0;
	c_mlx->b = 0;
	c_mlx->x_out = 2;
	c_mlx->y_out = 2;
	c_mlx->color = 0;
	c_mlx->hi = 4.00 / HEIGHT;
	c_mlx->wd = 4.00 / WIDTH;
	c_mlx->stop = 0;
	c_mlx->zy = 0;
	c_mlx->zx = 0;
}

void	invalid_input(int a)
{
	(void)a;
	ft_printf("  -invalid input :\n");
	ft_printf("\tavailable functions :");
	ft_printf("\n\t\t\t     Mandelbrot\n");
	ft_printf("\t\t\t     Julia\n");
	ft_printf("\t\t\t     burning ship\n");
}

void	ft_parcing(int ac, char **av, t_mlx *c_mlx)
{
	if (ac == 2)
	{
		if (ac == 2 && ft_strcmp("mandelbrot", av[1]) == 0)
		{
			c_mlx->digit = 1;
		}
		else if (ac == 2 && ft_strcmp("julia", av[1]) == 0)
				c_mlx->digit = 2;
		else if (ac == 2 && ft_strcmp("burning_ship", av[1]) == 0)
				c_mlx->digit = 3;
		else
		{
			invalid_input(1);
			exit(0);
		}
	}
	if (ac != 2)
	{
		invalid_input(1);
		exit(0);
	}
}

int	main(int ac, char *arv[])
{
	t_mlx	c_mlx;

	ft_parcing(ac, arv, &c_mlx);
	c_mlx.mlx_ptr = mlx_init();
	c_mlx.win_ptr = mlx_new_window(c_mlx.mlx_ptr, WIDTH, HEIGHT, "mandelbrot");
	c_mlx.img = mlx_new_image(c_mlx.mlx_ptr, WIDTH, HEIGHT);
	c_mlx.add = mlx_get_data_addr(c_mlx.img, \
		&c_mlx.bpp, &c_mlx.length_size, &c_mlx.endian);
	inis(&c_mlx);
	fractal(&c_mlx, 0);
	mlx_hook(c_mlx.win_ptr, 2, 0, handler, &c_mlx);
	mlx_hook(c_mlx.win_ptr, 17, 0, destroy, &c_mlx);
	if (c_mlx.digit == 2)
		mlx_hook(c_mlx.win_ptr, 6, 0, mouse_move_event, &c_mlx);
	mlx_hook(c_mlx.win_ptr, 4, 0, zoom_event, &c_mlx);
	mlx_hook(c_mlx.win_ptr, 6, 0, mouse_move_event, &c_mlx);
	mlx_loop(c_mlx.mlx_ptr);
}
