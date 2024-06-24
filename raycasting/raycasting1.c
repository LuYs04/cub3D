#include "../main/cube.h"

void	fill_colors(t_cube **cube, t_lst_col *col)
{
	while (col)
	{
		if (col->pos == 'C')
			(*cube)->ceiling = create_trgb(col->r, col->g, col->b);
		if (col->pos == 'F')
			(*cube)->floor = create_trgb(col->r, col->g, col->b);
		col = col->next;
	}
}

void	fill_textures(t_cube **cube, t_lst_txtr *txtr)
{
	(void)cube;
	while (txtr)
	{
		printf("--------dfghj\n");
		if (!strcmp(txtr->pos, "NO"))
			// (*mlx)->cube->no_img = mlx_xpm_file_to_image((*mlx)->mlx_p, \
			// txtr->path, 100, 100);
		if (!strcmp(txtr->pos, "SO"))
			// (*mlx)->cube->so_img = mlx_xpm_file_to_image((*mlx)->mlx_p, \
			// txtr->next->path, 100, 100);
		if (!strcmp(txtr->pos, "EA"))
			// (*mlx)->cube->ea_img = mlx_xpm_file_to_image((*mlx)->mlx_p, \
			// txtr->next->next->path, 100, 100);
		if (!strcmp(txtr->pos, "WE"))
			// (*mlx)->cube->we_img = mlx_xpm_file_to_image((*mlx)->mlx_p, \
			// txtr->next->next->next->path, 100, 100);
		txtr = txtr->next;
	}
}

void    start_game(t_mlx **mlx, t_lst_txtr *txtr, t_lst_col *col, t_list *map)
{
	(void)txtr;
    init_mlx(mlx);
	init_cube(mlx, map);
	fill_colors(&(*mlx)->cube, col);
	// fill_textures(&(*mlx)->cube, txtr);
	free_struct(txtr, col, map);
    img_init(*mlx);
	get_the_rays(mlx);
    mlx_key_hook((*mlx)->win, &key_manager, mlx);//2, 1L << 2, key_manager, mlx);
    mlx_loop((*mlx)->mlx_p);
}

