#include "parse.h"

void	init_info(t_info *info)
{
	info->n_texpath = ((void *)0);
	info->s_texpath = ((void *)0);
	info->w_texpath = ((void *)0);
	info->e_texpath = ((void *)0);
	info->map = ((void *)0);
	info->floor_color = -1;
	info->ceiling_color = -1;
	info->map_start_idx = -1;
	info->map_width = 0;
	info->map_height = 0;
	info->player_view = 0;
	info->player_x = 0;
	info->player_y = 0;
}

void	parser(t_info *info, char *path)
{
	int	fd;

	// file open
	fd = file_open(path);
	// init
	init_info(info);
	// map parsing validator

	// map validator

	// texture setting

	// file close
	close (fd);
}
