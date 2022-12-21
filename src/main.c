#include "./fractol.h"


int	key_hook(int button, int x, int y, t_init *param)
{
	printf("%d , %d ,%d \n",button,x,y);
	float range_x = ((float)x/param->width)*(param->x.max -(param->x.min))+(param->x.min);
	float range_y = ((float)y/param->hight)*(param->y.max - (param->y.min))+(param->y.min);
	if(button == 4)
	{
		param->x.min = range_x + ((param->x.min - range_x)*0.7);
		param->x.max = range_x + ((param->x.max - range_x)*0.7);
		param->y.min = range_y + ((param->y.min - range_y)*0.7);
		param->y.max = range_y + ((param->y.max - range_y)*0.7);
		param->max_itr += 2;
	}else if(button == 5){
		param->x.min = range_x + ((param->x.min - range_x)*1.1);
		param->x.max = range_x + ((param->x.max - range_x)*1.1);
		param->y.min = range_y + ((param->y.min - range_y)*1.1);
		param->y.max = range_y + ((param->y.max - range_y)*1.1);
		param->max_itr -= 2;

	}
	mlx_clear_window(param->mlx,param->win);
	mandelbrotSet(param);
	return (0);
}

int	main(void)
{
	t_init *dependency;
	
	dependency = init_dependency(800, 600);
	mandelbrotSet(dependency);
	mlx_mouse_hook(dependency->win, &key_hook, dependency);
	mlx_loop(dependency->mlx);
}
