/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:05:50 by aelarbid          #+#    #+#             */
/*   Updated: 2022/12/15 05:38:10 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    int width;
    int hight;
    int max_itr;
    float tmp;
    struct s_x
    {
        float min;
        float max;
    } x;
    struct s_y
    {
        float min;
        float max;
    } y;
    
    
} t_init;



#endif
