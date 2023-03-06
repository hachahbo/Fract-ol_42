/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:37:49 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/06 00:53:28 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "unchanging.h"
# include "ft_printf/ft_printf.h"

typedef struct o_list
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		ho;
	int		ve;
	int		bpp;
	int		length_size;
	int		endian;
	char	*where;
	void	*img;
	char	*add;
	double	i;
	double	j;
	double	x;
	double	y;
	int		digit;
	int		color;
	double	zoom;
	double	a;
	double	b;
	double	wd;
	int		it;
	double	hi;
	double	x_out;
	double	y_out;
	double	pos_x;
	double	pos_y;
	int		k;
	int		l;
	int		stop;
	double	zx;
	double	zy;
}	t_mlx;
int		ft_strcmp(char *s1, char *s2);
int		mouse_move_event(int x, int y, t_mlx *c_mlx);
int		julia(double a, double b, t_mlx *c_mlx);
int		TRGB(double i);
int		destroy(t_mlx *c_mlx);
int		handler(int keycode, t_mlx *c_mlx);
void	rendering_mandelbrot(t_mlx *c_mlx);
void	fractal(t_mlx *c_mlx, int a);
void	rendering_julia(t_mlx *c_mlx);
void	rendering_burning_ship(t_mlx *c_mlx);
int		choise_color(int i, t_mlx *c_mlx);
int		ft_shift(t_mlx *c_mlx);
int		zoom_event(int button, int x, int y, t_mlx *c_mlx);
#	endif