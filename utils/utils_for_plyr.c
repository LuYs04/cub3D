#include "../main/cube.h"

void get_pos(t_cube **cube, int y, int x)
{
    (*cube)->dt->mapX = x;
    (*cube)->dt->mapY = y;
}

int    arr2d_len(char **arr)
{
    int     i;

    i = 0;
    if (arr)
        while (arr[i])
            i++;
    return (i);
}

void get_player_data(t_cube **cube)
{
    int i;
    int count;

    i = -1;
    count = arr2d_len((*cube)->dt->map);
    while((*cube)->dt->map[++i])
    {
        if (strchr((*cube)->dt->map[i], 'N'))
            get_pos(cube, strlen((*cube)->dt->map[i]) - strlen(strchr((*cube)->dt->map[i], 'N')), i);
        else if (strchr((*cube)->dt->map[i], 'S'))
            get_pos(cube, strlen((*cube)->dt->map[i]) - strlen(strchr((*cube)->dt->map[i], 'S')), i);
        else if (strchr((*cube)->dt->map[i], 'W'))
            get_pos(cube, strlen((*cube)->dt->map[i]) - strlen(strchr((*cube)->dt->map[i], 'W')), i);
        else if (strchr((*cube)->dt->map[i], 'E'))
            get_pos(cube, strlen((*cube)->dt->map[i]) - strlen(strchr((*cube)->dt->map[i], 'E')), i);
        else
            count--;
    }
    if (count == 0)
        error("there is no player");
    if (count > 1)
        error("too many players");
    if ((*cube)->dt->mapX == 0  || (*cube)->dt->mapX == arr2d_len((*cube)->dt->map) - 1 
    || (*cube)->dt->mapY == 0 || (*cube)->dt->mapY == arr2d_len((*cube)->dt->map) - 1)
        error("player on edge");
    printf("\nx = %d, y = %d\n", (*cube)->dt->mapX, (*cube)->dt->mapY);
}
