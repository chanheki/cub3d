#include "parse.h"

void	initialize_info(t_info *info)
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

int	file_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error("File open");
	return (fd);
}

int	staging_map_checker(t_info *info)
{
	if (info->n_texpath == 0)
		return (0);
	if (info->s_texpath == 0)
		return (0);
	if (info->w_texpath == 0)
		return (0);
	if (info->e_texpath == 0)
		return (0);
	if (info->floor_color == -1)
		return (0);
	if (info->ceiling_color == -1)
		return (0);
	return (1);
}

int	is_just_new_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

void	fill_in_map_information(t_info *info)
{
	// strcmp info ~
}

void	map_parsing_validator(int fd, t_info *info)
{
	char	*line;

	while (!staging_map_checker(info))
	{
		line = get_next_line(fd);
		if (line == (void *)0)
			exit_with_error("Important map information is missing.");
		else if (is_just_new_line(line))
		{
			free(line);
			continue ;
		}
		else
			fill_in_map_information(info);
		free(line);
	}
}


void	parser(t_info *info, char *path)
{
	int	fd;

	fd = file_open(path);
	initialize_info(info);
	map_parsing_validator(fd, info);
	// map validator

	// texture setting

	close (fd);
}
