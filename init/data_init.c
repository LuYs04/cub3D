#include "../main/cube.h"

void    init_data(t_cube **cube, t_list *map)
{
    (*cube)->dt = malloc(sizeof(t_data));
    if (!(*cube)->dt)
        error("memory allocation failed");
    (*cube)->dt->map = lst_map_to_array(map, -1, -1, -1, -1);
    get_player_data(cube);
    (*cube)->dt->camX = 0.0;
    (*cube)->dt->camY = 0.0;
    (*cube)->dt->stepX = 0.0;
    (*cube)->dt->stepY = 0.0;
    (*cube)->dt->sideX = 0;
    (*cube)->dt->sideY = 0;
    (*cube)->dt->deltaX = 0;
    (*cube)->dt->deltaY = 0;
    (*cube)->dt->planeX = 0;
    (*cube)->dt->planeY = 0;
    (*cube)->dt->wallDist = 0;
    init_player_pos(*cube, (*cube)->dt->mapX, (*cube)->dt->mapY);
}

void init_plyr(t_cube **cube)
{
    (*cube)->ply = malloc(sizeof(t_player));
    if (!(*cube)->ply)
        error("memory allocation failed");
    (*cube)->ply->x = (*cube)->dt->mapX;
    (*cube)->ply->y = (*cube)->dt->mapY;
    (*cube)->ply->dirX = -1;
    (*cube)->ply->dirY = 0;
    (*cube)->ply->fov = (FOV * M_PI) / 180;
    (*cube)->ply->p_angle = M_PI;
}

void init_ray(t_cube **cube)
{
    (*cube)->ray = malloc(sizeof(t_ray));
    if (!(*cube)->ray)
        error("memory allocation failed");
    (*cube)->ray->dirX = 0.0;
    (*cube)->ray->dirY = 0.0;
}

void    init_cube(t_mlx **mlx, t_list *map)
{
    (*mlx)->cube = malloc(sizeof(t_cube));
    if (!(*mlx)->cube)
        error("memory allocation failed");
    // no_img... ??
    (*mlx)->cube->ceiling = 0;
    (*mlx)->cube->floor = 0;
    init_ray(&(*mlx)->cube);
    init_data(&(*mlx)->cube, map);
    init_plyr(&(*mlx)->cube);
}