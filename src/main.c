/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:34:00 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/22 05:51:22 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	key_hook(int keycode, t_init *vars)
{
	if (keycode == 53)
		exit(1);
	free(vars);
	return (0);
}

int	closea(t_init *dep)
{
	free(dep);
	exit(1);
	return (1);
}

int	main(int ac, char **av)
{
	t_init	*dependency;

	dependency = init_dependency(800, 600);
	if (ac > 1 && ft_strlen(av[1]) && (!ft_strncmp(av[1], "j1", 2)
			|| !ft_strncmp(av[1], "j2", 2) || !ft_strncmp(av[1], "m", 2)))
	{
		if (!ft_strncmp(av[1], "j1", 2) && ft_strlen(av[1]) == 2)
		{
			dependency->j.x = 0.835 ;
			dependency->j.y = 0.2321;
			juliatset(dependency);
			mlx_mouse_hook(dependency->win, &jzoom, dependency);
		}
		else if (!ft_strncmp(av[1], "j2", 2) && ft_strlen(av[1]) == 2)
		{
			dependency->j.x = -0.285 ;
			dependency->j.y = -0.01;
			juliatset(dependency);
			mlx_mouse_hook(dependency->win, &jzoom, dependency);
		}
		else if (!ft_strncmp(av[1], "m", 1) && ft_strlen(av[1]) == 1)
		{
			mandelbrotset(dependency);
			mlx_mouse_hook(dependency->win, &mzoom, dependency);
		}
	}
	else
	{
		ft_putstr_fd("////////////////////////////\n", 2);
		ft_putstr_fd("//   use the argument    //\n", 2);
		ft_putstr_fd("//   j1 for julia set 1  //\n", 2);
		ft_putstr_fd("//   j1 for julia set 2  //\n", 2);
		ft_putstr_fd("// m for Mandelbrot set 1//\n", 2);
		ft_putstr_fd("///////////////////////////\n", 2);
		return (0);
	}
	mlx_key_hook(dependency->win, &key_hook, dependency);
	mlx_hook(dependency->win, 17, 0, &closea, dependency);
	mlx_loop(dependency->mlx);
}
