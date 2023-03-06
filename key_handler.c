/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:02:33 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/06 00:44:49 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(t_mlx *c_mlx, int a)
{
	if (a == 1)
		mlx_destroy_image(c_mlx->mlx_ptr, c_mlx->img);
	if (c_mlx->digit == 1)
		rendering_mandelbrot(c_mlx);
	else if (c_mlx->digit == 2)
		rendering_julia(c_mlx);
	else if (c_mlx->digit == 3)
		rendering_burning_ship(c_mlx);
}

int	ft_shift(t_mlx *c_mlx)
{
	c_mlx->color = (c_mlx->color % 2) + 1;
	return (0);
}

void	ft_f(t_mlx *c_mlx)
{
	c_mlx->pos_x = c_mlx->l - (WIDTH) + c_mlx->i;
	c_mlx->pos_y = c_mlx->k - (HEIGHT) + c_mlx->j;
}

int	handler(int keycode, t_mlx *c_mlx)
{
	ft_f(c_mlx);
	if (keycode == 123)
	c_mlx->x_out -= 0.05;
	else if (keycode == 124)
		c_mlx->x_out += 0.05;
	else if (keycode == 125)
		c_mlx->y_out -= 0.05;
	else if (keycode == 126)
		c_mlx->y_out += 0.05;
	else if (keycode == 2)
		c_mlx->i -= 30;
	else if (keycode == 0)
		c_mlx->i += 30;
	else if (keycode == 13)
		c_mlx->j += 30;
	else if (keycode == 1)
		c_mlx->j -= 30;
	else if (keycode == 53 || keycode == 17)
		destroy(c_mlx);
	if (keycode == 257)
		ft_shift(c_mlx);
	fractal(c_mlx, 0);
	return (0);
}
