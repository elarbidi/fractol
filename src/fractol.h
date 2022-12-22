/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:05:50 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/22 05:49:35 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
# define FRACTOL_H

# include"../libft/libft.h"
# include	"mlx.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		hight;
	int		max_itr;
	int		itr;
	struct	s_x
	{
		float	min;
		float	max;
	}	x;
	struct	s_y
	{
		float	min;
		float	max;
	}	y;
	struct	s_j
	{
		float	x;
		float	y;
	}	j;
}	t_init;

typedef struct ij
{
	int		i;
	int		j;
}	t_ij;

t_init	*init_dependency(int width, int hight);
void	mandelbrotset(t_init *dependency);
void	printpixels(t_init *dep, int x, int y, int itr);
void	juliatset(t_init *dependency);
int		jzoom(int button, int x, int y, t_init *param);
int		mzoom(int button, int x, int y, t_init *param);

#endif
