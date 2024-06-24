#include "../main/cube.h"

void init_mlx(t_mlx **mlx)
{
    (*mlx)->mlx_p = mlx_init();
    (*mlx)->win = mlx_new_window((*mlx)->mlx_p, WIDTH, HEIGHT, "Cube3D");
    (*mlx)->img = mlx_new_image((*mlx)->mlx_p, 	WIDTH, HEIGHT);
    (*mlx)->addr = mlx_get_data_addr((*mlx)->img, &(*mlx)->bits_per_pixel, &(*mlx)->line_length,
								&(*mlx)->endian);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	img_init(t_mlx *data)
{
	if (data->mlx_p && data->img)
		mlx_destroy_image(data->mlx_p, data->img);
	data->img = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, \
			&data->bits_per_pixel, \
			&data->line_length, &data->endian);
	draw_f_c(data, data->cube->ceiling, data->cube->floor);
	return (0);
}