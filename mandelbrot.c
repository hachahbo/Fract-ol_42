/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:21:17 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/05 23:24:39 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int j, int i, t_mlx *c_mlx)
{
	double	z_a;
	double	z_b;
	double	old;

	z_b = 0;
	z_a = 0;
	c_mlx->it = 0;
	c_mlx->a = i * c_mlx->wd - c_mlx->x_out + c_mlx->pos_x;
	c_mlx->b = j * c_mlx->wd - c_mlx->y_out + c_mlx->pos_y;
	while (c_mlx->it < IT && (z_b * z_b + z_a * z_a) <= 4.0)
	{
		old = z_a;
		z_a = (z_a * z_a) - (z_b * z_b) + c_mlx->a;
		z_b = (2 * old * z_b) + c_mlx->b;
		c_mlx->it++;
	}
	return (c_mlx->it);
}

void	rendering_mandelbrot(t_mlx *c_mlx)
{
	int	man;

	c_mlx->k = 0;
	while (c_mlx->k < HEIGHT)
	{
		c_mlx->l = 0;
		while (c_mlx->l < WIDTH)
		{
			man = (mandelbrot(c_mlx->k, c_mlx->l, c_mlx) / IT) * 255;
			c_mlx->where = c_mlx->add + \
			(c_mlx->k * c_mlx->length_size) + (c_mlx->l * (c_mlx->bpp / 8));
			*(int *) c_mlx->where = choise_color(man, c_mlx);
			c_mlx->l++;
		}
		c_mlx->k++;
	}
	mlx_clear_window(c_mlx->mlx_ptr, c_mlx->win_ptr);
	mlx_put_image_to_window(c_mlx->mlx_ptr, c_mlx->win_ptr, c_mlx->img, 0, 0);
}
