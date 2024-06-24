#include "../main/cube.h"

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	draw_f_c(t_mlx *mlx, int c, int f)
{
	int	i;
	int	j;

	(void)c;(void)f;
	i = -1;
	while (++i < HEIGHT / 2)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(mlx, j, i, c);//0xde1a24);
	}
	i = HEIGHT / 2 - 1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(mlx, j, i, f);//0x759116);
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->img, 0, 0);
}

// petq chi :)
void draw(t_mlx **mlx)
{
    int x;
    int y;

    x = -1;
    while (++x < 10)
    {
        y = -1;
        while (++y < 10)
            my_mlx_pixel_put(*mlx, x + 500, y + 500, 0xFFFFFF);
    }
    x = -1;
    while (++x < 200)
    {
        y = -1;
        while (++y < 10)
            my_mlx_pixel_put(*mlx, y + 400, x + 400, 0xFFAAAA);
    }
    mlx_put_image_to_window((*mlx)->mlx_p, (*mlx)->win, (*mlx)->img, 0, 0);
}

