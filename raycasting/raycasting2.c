#include "../main/cube.h"

void    get_first_step(t_cube **c)
{
    if ((*c)->ray->dirX < 0)
	{
		(*c)->dt->stepX = -1;
		(*c)->dt->sideX = ((*c)->ply->x - (*c)->dt->mapX) * (*c)->dt->deltaX;
	}
	else
	{
		(*c)->dt->stepX = 1;
		(*c)->dt->sideX = ((*c)->dt->mapX + 1.0 - (*c)->ply->x) * (*c)->dt->deltaX;
	}
	if ((*c)->ray->dirY < 0)
	{
		(*c)->dt->stepY = -1;
		(*c)->dt->sideY = ((*c)->ply->y - (*c)->dt->mapY) * (*c)->dt->deltaY;
	}
	else
	{
		(*c)->dt->stepY = 1;
		(*c)->dt->sideY = ((*c)->dt->mapY + 1.0 - (*c)->ply->y) * (*c)->dt->deltaY;
	}
}

void dda_alg(t_cube **c)
{
	while (1)
    {
        if ((*c)->dt->sideX < (*c)->dt->sideY)
        {
        	(*c)->dt->sideX += (*c)->dt->deltaX;
        	(*c)->dt->mapX += (*c)->dt->stepX;
        	(*c)->dt->side = 0;
        }
        else
        {
        	(*c)->dt->sideY += (*c)->dt->deltaY;
        	(*c)->dt->mapY += (*c)->dt->stepY;
        	(*c)->dt->side = 1;
        }
        if ((*c)->dt->map[(*c)->dt->mapX][(*c)->dt->mapY] == '1')
			break ;
	}
	if((*c)->dt->side == 0)
		(*c)->dt->wallDist = (*c)->dt->sideX - (*c)->dt->deltaX;
    else
		(*c)->dt->wallDist = (*c)->dt->sideY - (*c)->dt->deltaY;
}

void	draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix) //?????????????????
{
	while (t_pix < b_pix)
		my_mlx_pixel_put(mlx, ray, t_pix++, 0x759116);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->img, 0, 0);
}

void	get_wall_dist___esim(t_cube **c)
{
	(*c)->ray->length = (int)(HEIGHT / (*c)->dt->wallDist);
	(*c)->ray->drawStart = -(*c)->ray->length / 2 + HEIGHT / 2;
    if((*c)->ray->drawStart < 0)
		(*c)->ray->drawStart = 0;
    (*c)->ray->drawEnd = (*c)->ray->length / 2 + HEIGHT / 2;
    if((*c)->ray->drawEnd >= HEIGHT)
		(*c)->ray->drawEnd = HEIGHT - 1;
}

void    get_the_rays(t_mlx **mlx)
{
    int r;

    r = -1;
	t_cube *cube = (*mlx)->cube;
    while (++r < WIDTH)
    {
        cube->dt->mapX = (int)cube->ply->x;
        cube->dt->mapY = (int)cube->ply->y;
        cube->dt->camX = 2 * r / (double)WIDTH - 1;
        cube->ray->dirX = cube->ply->dirX + cube->dt->planeX * \
        cube->dt->camX;
        cube->ray->dirY = cube->ply->dirY + cube->dt->planeY * \
        cube->dt->camY;
		if (cube->ray->dirX == 0)
			cube->dt->deltaX = 1e30;
        else
			cube->dt->deltaX = fabs(1 / cube->ray->dirX);
	    if (cube->ray->dirY == 0)
			cube->dt->deltaY = 1e30;
		else
			cube->dt->deltaY = fabs(1 / cube->ray->dirY);
		get_first_step(&cube);
		dda_alg(&cube);
		get_wall_dist___esim(&cube);
		draw_wall(*mlx, r, cube->ray->drawStart, cube->ray->drawEnd);
    }
}
