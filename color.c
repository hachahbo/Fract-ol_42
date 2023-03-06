/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:25:30 by hachahbo          #+#    #+#             */
/*   Updated: 2023/03/06 04:21:28 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int black_white(int man)
{
	int t = 0;
	
	return(t << 24 | man << 16 | man << 8 | man);
}
int	TRGB1(double i)
{
	int		color;
	double	ratio;

	// color = 0;
	// ratio = i / 90;
	// color = ((unsigned char)(8.00 * (2 - ratio)) * pow(ratio, 2) * 255 );
	// color = (color << 8);//| (unsigned char)(10 * pow((1 - ratio), 2) * 255);
	// // color = (color << 8) | (unsigned char)(8.5 * pow((1 - ratio), 3) * ratio
	// // 		* 255);
	// return (color);
	color = 0;
	ratio = i / 80.00;
	color = (unsigned char)(8 * (1 - ratio) * pow(ratio, 2) * 255);
	 // color = (color << 8) | (unsigned char)(15 * pow((1 - ratio), 2) * 255);
	// color = (color << 8) | (unsigned char)(8.5 * pow((1 - ratio), 3) * ratio
	//  	* 255);
	return (color);
}
int	TRGB2(double i)
{	
	int t = i /IT;
// 	int		color;
// 	double	ratio;

// 	color = 0;
// 	ratio = i / IT;
// 	color = ((unsigned char)(9 * (1 - ratio)) * pow(ratio, 2.00) * 255 );
// 	color = (color << 8) | (unsigned char)(10 * pow((1 - ratio), 2) * 255);
// 	//color = (color << 8) ;//| (unsigned char)(8.5 * pow((1 - ratio), 3) * ratio
// 	//		* 255);
// 	return (color);
	int r, g,b;
	 if(i <= IT)
    {
        if (t < 2) {  // Darker shade of gold
            r = 180;
            g = (int) (165 * t / 0.2);
            b = 0;
        } else if (t < 5) {  // Medium shade of gold
            r = (int) (255 * (t - 0.2) / 0.3);
            g = 165;
            b = 0;
        } else 
        {  // Lighter shade of gold
            r = 255;
            g = (int) (165 - 20 * (t - 0.5) / 0.5);
            b = 0;
        }
    return((r << 16) + (g << 8) + b );
    }
	return(0);
 }
// int	TRGB3(double i, t_mlx *c_mlx)
// {
// 	int		color;
// 	double	ratio;

// 	colo 

int choise_color(int i, t_mlx *c_mlx)
{
	if(c_mlx->color == 0)
		return(black_white(i));
	else if(c_mlx->color == 1)
		return(TRGB1(i));
	else if(c_mlx->color == 2)
	 	return(TRGB2(i));
	// else if(c_mlx->color == 3)
	// 	black_white(i);
	return(0);
}
