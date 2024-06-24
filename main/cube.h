#ifndef CUBE_H
#define CUBE_H

#include "mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/get_next_line.h"
#include "../libft/libft.h"

# define WIDTH 1500
# define HEIGHT 1000

# define PI             3.14
# define FOV            60
// # define CUBE_SIZE      30
# define MOVE_SPEED		0.2
# define ROTATE_SPEED	0.15

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define A				0
# define S				1
# define D				2
# define W				13

typedef struct s_lst_txtr
{ 
    char    *pos;
    char    *path;
    struct s_lst_txtr *next;
}       t_lst_txtr;

typedef struct s_lst_col
{
    char    pos;
    int     r;
    int     g;
    int     b;
    struct s_lst_col *next;
}       t_lst_col;

typedef struct  s_data
{
    char    **map;
    int     side;
    int     mapX; //map-i tvyal cube-i X
    int     mapY; //map-i tvyal cube-i Y
    double  camX;
    double  camY;
    double  stepX;
    double  stepY;
    double  sideX;
    double  sideY;
    double  deltaX;
    double  deltaY;
    double  planeX;
    double  planeY;
    double  wallDist;
}       t_data;

typedef struct  s_player
{
    double     x;
    double     y;
    double  dirX;
    double  dirY;
    double  fov;
    double  p_angle;
}       t_player;

typedef struct s_ray
{
    double  dirX;
    double  dirY;
    int     length;
    int     drawStart;
    int     drawEnd;
}       t_ray;

typedef struct s_cube
{
    // void        *no_img;
    // void        *so_img;
    // void        *ea_img;
    // void        *we_img;
    int         ceiling;
    int         floor;
    t_player    *ply;
    t_data      *dt;
    t_ray       *ray;
}       t_cube;

typedef struct  s_mlx
{
    void        *mlx_p;
    void        *img;
    void        *win;
    char	    *addr;
	int		    bits_per_pixel;
	int         line_length; //???
	int         endian;
    t_cube      *cube;
   
}       t_mlx;

void    get_info(t_lst_col **col, t_lst_txtr **txtr, t_list **map, char *s, t_list **head);
void    get_lists(t_list  *lst, t_list  **map, t_lst_col **col, t_lst_txtr **txtr);
void    start_game(t_mlx **mlx, t_lst_txtr *txtr, t_lst_col *col, t_list *map);
char    **lst_map_to_array(t_list *map, int len, int line_len, int i, int j);
void    free_struct(t_lst_txtr *txtr, t_lst_col *col, t_list *lst);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	init_player_pos(t_cube *cube, int i, int j);
void    get_colors(t_lst_col **col, char *str);
void    init_cube(t_mlx **mlx, t_list *map);
void	draw_f_c(t_mlx *mlx, int c, int f);
int     key_manager(int key, t_mlx **mlx);
int     create_trgb(int r, int g, int b);
void    read_file(t_list **lst, int fd);
void    get_player_data(t_cube **cube);
void    print_txtr(t_lst_txtr *txtr);
void    check_before_split(char *s);
void    check_extension(char *str);
int     check_is_that_map(char *s);
void    check_col_line(char *line);
void    get_the_rays(t_mlx **mlx);
void    ignore_spaces(char **str);
void    check_rgb(t_lst_col *col);
void    print_col(t_lst_col *col);
void    check_txtr_pos(char *str);
int     get_max_line(t_list *map);
int     len_txtr(t_lst_txtr *t);
void    free_data(t_mlx **mlx);
void    print_lst(t_list *lst);
void    free_lst(t_list *lst);
int     len_col(t_lst_col *c);
void    init_mlx(t_mlx **mlx);
void    check_map(char **map);
int     img_init(t_mlx *data);
int     check_col(char *c);
void    draw(t_mlx **mlx);
void    error(char *str);


#endif