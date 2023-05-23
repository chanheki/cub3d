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

void	check_file_access(char *info_path, char *value)
{
	int	fd;

	if (info_path != NULL)
		exit_with_error("Duplicate Check");
	info_path = value;
	fd = open(value, O_RDONLY);
	if (fd == -1)
		exit_with_error("Inaccessible file");
	close(fd);
}

unsigned int	rgb_to_hex(char *rgb)
{
	int				r;
	int				g;
	int				b;
	char			**rgb_arr;

	rgb_arr = ft_split(rgb, ',');
	// if (ftt_double_arr_len(rgb_arr) != 3)
	// 	exit_with_error("num of RGB value is not valid");
	if (ft_strlen(rgb_arr[0]) > 3 || ft_strlen(rgb_arr[1]) > 3
		|| ft_strlen(rgb_arr[2]) > 4)
		exit_with_error("RGB value is not valid");
	r = ft_atoi(rgb_arr[0]);
	g = ft_atoi(rgb_arr[1]);
	if (rgb_arr[2][0] == '\n')
		exit_with_error("RGB value is not valid");
	b = ft_atoi(rgb_arr[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_with_error("RGB value is not valid");
	// free_double_arr(rgb_arr);
	free (rgb);
	return ((r << 16) + (g << 8) + b);
}

void	fill_in_map_information(char *line, t_info *info)
{
	char	**splited_value;
	char	*key;
	char	*path;

	splited_value = ft_split(line, ' ');
	key = splited_value[0];
	path = splited_value[1];
	if (key == NULL || path == NULL)
		exit_with_error("Invalid map informations");
	else if (!ft_strcmp(key, "NO"))
		check_file_access(info->n_texpath, path);
	else if (!ft_strcmp(key, "WE"))
		check_file_access(info->w_texpath, path);
	else if (!ft_strcmp(key, "EA"))
		check_file_access(info->e_texpath, path);
	else if (!ft_strcmp(key, "SO"))
		check_file_access(info->s_texpath, path);
	else if (!ft_strcmp(key, "F"))
		info->floor_color = rgb_to_hex(path);
	else if (!ft_strcmp(key, "C"))
		info->ceiling_color = rgb_to_hex(path);
	else
		exit_with_error("Invalid information");
	free(path);
	free(key);
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
			fill_in_map_information(line, info);
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
