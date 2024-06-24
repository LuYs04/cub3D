#include "../main/cube.h"

void	rotate(t_cube **cube, double rotate)
{
	double	old_pos;

	old_pos = (*cube)->ray->dirX;
	(*cube)->ray->dirX = old_pos * cos(rotate) - (*cube)->ray->dirY * sin(rotate);
	(*cube)->ray->dirY = old_pos * sin(rotate) + (*cube)->ray->dirY * cos(rotate);
	old_pos = (*cube)->dt->planeX;
	(*cube)->dt->planeX = old_pos * cos(rotate) - (*cube)->dt->planeY * sin(rotate);
	(*cube)->dt->planeY = old_pos * sin(rotate) + (*cube)->dt->planeX * cos(rotate);
	printf("planeeee = %f,   %f\n", (*cube)->dt->planeX, (*cube)->dt->planeY);
}

void	move_left(t_cube **cube)
{
// 	int	x;
// 	int	y;

// 	x = (int)((*cube)->ply->x - (*cube)->dt->planeX * (MOVE_SPEED + 0.1));
// 	y = (int)(*cube)->ply->y;
// 	if ((*cube)->dt->map[x][y] == '0')
// 		(*cube)->ply->x -= (*cube)->dt->planeX * MOVE_SPEED;
// 	x = (int)(*cube)->ply->x;
// 	y = (int)((*cube)->ply->y - (*cube)->dt->planeY * \
// 	(MOVE_SPEED + 0.1));
// 	if ((*cube)->dt->map[x][y] == '0')
// 		(*cube)->ply->y -= (*cube)->dt->planeY * MOVE_SPEED;

	if ((*cube)->dt->map[(int)((*cube)->ply->x - (*cube)->dt->planeX * \
	 (MOVE_SPEED + 0.1))][(int)(*cube)->ply->y] == '0')
		(*cube)->ply->x -= (*cube)->dt->planeX * MOVE_SPEED;
	
	if ((*cube)->dt->map[(int)(*cube)->ply->x][(int)((*cube)->ply->y - (*cube)->dt->planeY * \
	 (MOVE_SPEED + 0.1))] == '0')
		(*cube)->ply->y -= (*cube)->dt->planeY * MOVE_SPEED;

	printf("L -- %f\t-- %f\n", (*cube)->ply->x, (*cube)->ply->y);
}

void	move_right(t_cube **cube)
{
	// int	x;
	// int	y;

	// x = (int)((*cube)->ply->x + (*cube)->dt->planeX * \
	// (MOVE_SPEED + 0.1));
	// y = (int)(*cube)->ply->y;
	// if ((*cube)->dt->map[x][y] == '0')
	// 	(*cube)->ply->x += (*cube)->dt->planeX * MOVE_SPEED;
	// x = (int)(*cube)->ply->x;
	// y = (int)((*cube)->ply->y + (*cube)->dt->planeY * \
	// (MOVE_SPEED + 0.1));
	// if ((*cube)->dt->map[x][y] == '0')
	// 	(*cube)->ply->y += (*cube)->dt->planeY * MOVE_SPEED;

	if ((*cube)->dt->map[(int)((*cube)->ply->x + (*cube)->dt->planeX * \
	 (MOVE_SPEED + 0.1))][(int)(*cube)->ply->y] == '0')
		(*cube)->ply->x += (*cube)->dt->planeX * MOVE_SPEED;
	
	if ((*cube)->dt->map[(int)(*cube)->ply->x][(int)((*cube)->ply->y + (*cube)->dt->planeY * \
	 (MOVE_SPEED + 0.1))] == '0')
		(*cube)->ply->y += (*cube)->dt->planeY * MOVE_SPEED;

	printf("R -- %f\t-- %f\n", (*cube)->ply->x, (*cube)->ply->y);
}

void	move_up(t_cube **cube)
{
	// int	x;
	// int	y;

	// x = (int)((*cube)->ply->x + \
	// (*cube)->ply->dirX * (MOVE_SPEED + 0.1));
	// y = (int)(*cube)->ply->y;
	// if ((*cube)->dt->map[x][y] == '0')
	// 	(*cube)->ply->x += (*cube)->ply->dirX * MOVE_SPEED;
	// x = (int)(*cube)->ply->x;
	// y = (int)((*cube)->ply->y + \
	// (*cube)->ply->dirY * (MOVE_SPEED + 0.1));
	// if ((*cube)->dt->map[x][y] == '0')
	// 	(*cube)->ply->y += (*cube)->ply->dirY * MOVE_SPEED;

	if ((*cube)->dt->map[(int)((*cube)->ply->x + \
	(*cube)->ply->dirX * (MOVE_SPEED + 0.1))][(int)(*cube)->ply->y] == '0')
		(*cube)->ply->x += (*cube)->ply->dirX * MOVE_SPEED;
	if ((*cube)->dt->map[(int)(*cube)->ply->x][(int)((*cube)->ply->y + \
	(*cube)->ply->dirY * (MOVE_SPEED + 0.1))] == '0')
		(*cube)->ply->y += (*cube)->ply->dirY * MOVE_SPEED;

	printf("U -- %f\t-- %f\n", (*cube)->ply->x, (*cube)->ply->y);
}

void	move_down(t_cube **cube)
{
	// int	x;
	// int	y;

	// x = (int)((*cube)->ply->x - \
	// (*cube)->ply->dirX * (MOVE_SPEED + 0.1));
	// y = (int)(*cube)->ply->y;
	// if ((*cube)->dt->map[x][y] == '0')
	// 	(*cube)->ply->x -= (*cube)->ply->dirX * MOVE_SPEED;
	// x = (int)(*cube)->ply->x;
	// y = (int)((*cube)->ply->y - \
	// (*cube)->ply->dirY * (MOVE_SPEED + 0.1));
	// if ((*cube)->dt->map[x][y] == '0')
	// 	(*cube)->ply->y -= (*cube)->ply->dirY * MOVE_SPEED;

	if ((*cube)->dt->map[(int)((*cube)->ply->x - \
	(*cube)->ply->dirX * (MOVE_SPEED + 0.1))][(int)(*cube)->ply->y] == '0')
		(*cube)->ply->x -= (*cube)->ply->dirX * MOVE_SPEED;
	if ((*cube)->dt->map[(int)(*cube)->ply->x][(int)((*cube)->ply->y - \
	(*cube)->ply->dirY * (MOVE_SPEED + 0.1))] == '0')
		(*cube)->ply->y -= (*cube)->ply->dirY * MOVE_SPEED;
	printf("D -- %f\t-- %f\n", (*cube)->ply->x, (*cube)->ply->y);
}

void	escape(t_mlx **mlx)
{
	if ((*mlx)->mlx_p && (*mlx)->img)
		mlx_destroy_image((*mlx)->mlx_p, (*mlx)->img);
	mlx_clear_window((*mlx)->mlx_p, (*mlx)->win);
	mlx_destroy_window((*mlx)->mlx_p, (*mlx)->win);
	free_data(mlx);
	// system("leaks cub3D");
	exit(0);
}

int	key_manager(int key, t_mlx **mlx)
{
	if (key == ESC)
		escape(mlx);
	if (key == RIGHT)
		rotate(&(*mlx)->cube, -ROTATE_SPEED);
	if (key == LEFT)
		rotate(&(*mlx)->cube, ROTATE_SPEED);
	if (key == A)
		move_left(&(*mlx)->cube);
	if (key == D)
		move_right(&(*mlx)->cube);
	if (key == W)
		move_up(&(*mlx)->cube);
	if (key == S)
		move_down(&(*mlx)->cube);
	img_init(*mlx);
	get_the_rays(mlx);
	// change_pos();
	// get_player_data(&(*mlx)->cube);
	// init_player_pos((*mlx)->cube, (*mlx)->cube->dt->mapX, (*mlx)->cube->dt->mapY);
	return (0);
}