#include "../main/cube.h"

void	initPLANE(t_cube *c, double i, double j)
{
	c->dt->planeX = i;
	c->dt->planeY = j;
}

void	initDIR(t_cube *c, double i, double j)
{
	c->ray->dirX = i;
	c->ray->dirY = j;
}

void	init_player_pos(t_cube *cube, int i, int j)
{
	if (cube->dt->map[i][j] == 'S')
	{
		initDIR(cube, 0, 1);
		initPLANE(cube, 0, -0.66);
		
	}
	else if (cube->dt->map[i][j] == 'N')
	{
		initDIR(cube, 0, -1);
		initPLANE(cube, 0, 0.66);
	}
	else if (cube->dt->map[i][j] == 'E')
	{
		initDIR(cube, 1, 0);
		initPLANE(cube, 0.66, 0);
	}
	else if (cube->dt->map[i][j] == 'W')
	{
		initDIR(cube, -1, 0);
		initPLANE(cube, -0.66, 0);
	}
}