/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:35:27 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/06 00:47:08 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "unchanging.h"

int	mouse_move_event(int x, int y, t_mlx *c_mlx)
{
	c_mlx->x = x;
	c_mlx->y = y;
	if (!c_mlx->stop)
	{
		c_mlx->zx = (c_mlx->x - HEIGHT / 2) / HEIGHT;
		c_mlx->zy = (c_mlx->y - HEIGHT / 2) / HEIGHT;
	}
	fractal(c_mlx, 0);
	return (0);
}

int	zoom_event(int button, int x, int y, t_mlx *c_mlx)
{
	(void) x;
	(void) y;
	if (button == 4)
	{	
		c_mlx->x_out = c_mlx->x_out + (c_mlx->x * c_mlx->wd);
		c_mlx->y_out = c_mlx->y_out + (c_mlx->y * c_mlx->hi);
		c_mlx->wd *= 2;
		c_mlx->hi *= 2;
		fractal(c_mlx, 0);
	}
	if (button == 5)
	{	
		c_mlx->wd /= 2;
		c_mlx->hi /= 2;
		c_mlx->x_out = c_mlx->x_out - (c_mlx->x * c_mlx->wd);
		c_mlx->y_out = c_mlx->y_out - (c_mlx->y * c_mlx->hi);
		fractal(c_mlx, 0);
	}
	if (button == 1)
		c_mlx->stop = !c_mlx->stop;
	return (0);
}
