/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printPx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:43:14 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/21 01:43:17 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"




void printPixels(void *mlx_ptr, void *win_ptr, int x, int y,int itr){
	static const int	color[15] = {
		4333071, //brown
		1640218, //	dark purple
		590127, // light purple
		1892,
		263241, // blue-marine
		797834,
		1594033, //blue
		3767761, //blue2
		8828389, //blue light
		13888760, //blue very light
		16304479, // yllow wall
		16755200, //yellow multard
		13402112, //yellow brownish
		10049280, //brown
		6960131 //dark brown
	};
	mlx_pixel_put(mlx_ptr,win_ptr, x, y,color[itr % 16]);

}