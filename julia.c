/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:19:23 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/06 00:42:13 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double a, double b, t_mlx *c_mlx)
{
	double	z_a;
	double	z_b;
	double	zx;
	double	zy;
	double	old;

	c_mlx->it = 0;
	zx = c_mlx->zx;
	zy = c_mlx->zy;
	z_a = b * c_mlx->wd - c_mlx->x_out;
	z_b = a * c_mlx->wd - c_mlx->y_out;
	while (c_mlx->it < ITER && (z_a * z_a + z_b * z_b) <= 4.00)
	{
		old = z_a;
		z_a = z_a * z_a - z_b * z_b + zx;
		z_b = (2 * old * z_b) + zy;
		c_mlx->it++;
	}
	return (c_mlx->it);
}

void	rendering_julia(t_mlx *c_mlx)
{
	int	man;

	c_mlx->k = 0;
	while (c_mlx->k < HEIGHT)
	{
		c_mlx->l = 0;
		while (c_mlx->l < WIDTH)
		{
			man = (julia(c_mlx->k, c_mlx->l, c_mlx) / IT) * 255;
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
