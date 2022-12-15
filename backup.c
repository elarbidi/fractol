#include "./fractol.h"






t_init *init_dependency(int width, int hight)
{
    t_init  *dependency;

    dependency = malloc(sizeof(t_init));
	dependency->width = width;
	dependency->hight = hight;
	dependency->x.max = 1.7;
	dependency->x.min = -2.0;
	dependency->y.max = 1.2;
	dependency->y.min = -1.2;
	dependency->max_itr = 100;
	dependency->mlx = mlx_init();
	dependency->win = mlx_new_window(dependency->mlx, width, hight, "fractol");
	dependency->img = mlx_new_image(dependency->mlx, width, hight);
	return (dependency);
}
void	mandelbrotSet(t_init *dependency){
	int i = 0;
	int j = 0;
	float x;
	float y;
	int itr;

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
	j=0;
	while( j < dependency->hight){
		i = 0;
		while(i < dependency->width){
			x = 0;
			y = 0;
			float a = ((float)i/dependency->width)*(dependency->x.max -(dependency->x.min))+(dependency->x.min);
			float b=((float)j/dependency->hight)*(dependency->y.max - (dependency->y.min))+(dependency->y.min);
		
			itr = 0;
			dependency->tmp = 0;
			while(itr < dependency->max_itr){
			/*	dependency->tmp = x*x - y*y -0.70176; //((float)i/dependency->width)*(dependency->x.max -(dependency->x.min))+(dependency->x.min);
				y	= 2.0*x*y -0.3842; //((float)j/dependency->hight)*(dependency->y.max - (dependency->y.min))+(dependency->y.min);
				x = dependency->tmp;*/
				float aa = a * a ;
				float bb = b*b;
				float twoab = 2 *a * b;
				a = aa-bb-0.70176;
				b = twoab - 0.3842;
				if(aa*bb > 4.0){
					break;
				}
				itr++;
			}
			if(0 < itr  && itr < dependency->max_itr){
				mlx_pixel_put(dependency->mlx,dependency->win, i, j,color[itr % 16]);
			}
			i++;
		}
		j++;
	}
}

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

	dependency = init_dependency(1200, 900);
	mandelbrotSet(dependency);
	mlx_mouse_hook(dependency->win, &key_hook, dependency);
	mlx_loop(dependency->mlx);
}
