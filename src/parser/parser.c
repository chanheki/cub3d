#include "parse.h"

void	initialize_info(t_info *info)
{
	info->n_texpath = NULL;
	info->s_texpath = NULL;
	info->w_texpath = NULL;
	info->e_texpath = NULL;
	info->map = NULL;
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

int	ft_strlen_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_file_access(char **info_path, char *value)
{
	int	fd;
	int	end;

	if (*info_path != NULL)
		exit_with_error("Duplicate Check");
	*info_path = ft_strdup(value);
	end = ft_strlen_index(*info_path);
	info_path[0][end - 1] = '\0';
	fd = open(*info_path, O_RDONLY);
	if (fd == -1)
		exit_with_error("Inaccessible file");
	close(fd);
}

int	check_rgb_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	rgb_validator(int r, int g, int b, char **rgb_arr)
{
	int	i;

	i = -1;
	if (check_rgb_len(rgb_arr) != 3)
		exit_with_error("num of RGB value is not valid");
	if (ft_strlen(rgb_arr[0]) > 3 || ft_strlen(rgb_arr[1]) > 3
		|| ft_strlen(rgb_arr[2]) > 4)
		exit_with_error("RGB value is not valid");
	while (++i < 3)
	{
		if (ft_strlen(rgb_arr[i]) == 1
			&& (rgb_arr[i][0] == '+' || rgb_arr[i][0] == '-'
			|| rgb_arr[i][0] == '\n'))
			exit_with_error("RGB value is not valid");
	}
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_with_error("RGB value is not valid");
}

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

unsigned int	rgb_to_hex(char *rgb)
{
	int				r;
	int				g;
	int				b;
	char			**rgb_arr;

	rgb_arr = ft_split(rgb, ',');
	r = ft_atoi(rgb_arr[0]);
	g = ft_atoi(rgb_arr[1]);
	b = ft_atoi(rgb_arr[2]);
	rgb_validator(r, g, b, rgb_arr);
	free_double_arr(rgb_arr);
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
		check_file_access(&info->n_texpath, path);
	else if (!ft_strcmp(key, "WE"))
		check_file_access(&info->w_texpath, path);
	else if (!ft_strcmp(key, "EA"))
		check_file_access(&info->e_texpath, path);
	else if (!ft_strcmp(key, "SO"))
		check_file_access(&info->s_texpath, path);
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
		if (line == NULL)
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
	if (info->floor_color == info ->ceiling_color)
		exit_with_error("must be able to set the floor and \
		ceiling colors to two different ones.");
}

char	*map_newline_pushing(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			exit_with_error("map is missing.");
		if (is_just_new_line(line))
		{
			free(line);
			continue ;
		}
		break ;
	}
	return (line);
}

void	map_board_parsing(int fd, t_info *info)
{
	char	*line;
	int		h;

	line = map_newline_pushing(fd);
	h = -1;
	info->map = (char **)ft_calloc(sizeof(char *), MAP_MAXHEIGHT);
	while (1)
	{
		if (line == NULL)
			break ;
		else if (is_just_new_line(line))
		{
			free(line);
			exit_with_error("Empty lines can't come in.");
			continue ;
		}
		else
			info->map[++h] = line;
		if (h > MAP_MAXHEIGHT)
			exit_with_error("Map size is too large");
		line = get_next_line(fd);
	}
	info->map_height = h;
}

void	map_board_validator(t_info *info)
{
	info->player_view = 'W';
	info->player_x = 12;
	info->player_y = 6;
}

void	show_map(t_info *info)
{
	for (int i = 0 ; i <= info->map_height ; i ++)
	{
		printf("%s \n", info->map[i]);
	}
}

void	parser(t_info *info, char *path)
{
	int	fd;

	fd = file_open(path);
	initialize_info(info);
	map_parsing_validator(fd, info);
	map_board_parsing(fd, info);
	close (fd);
	map_board_validator(info);
}
