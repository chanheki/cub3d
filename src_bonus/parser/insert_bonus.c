/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:31:53 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 19:32:21 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "constant.h"

void	initialize_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_MAXHEIGHT)
	{
		j = 0;
		while (j < MAP_MAXWIDTH)
		{
			info->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	initialize_info(t_info *info)
{
	info->n_texpath = NULL;
	info->s_texpath = NULL;
	info->w_texpath = NULL;
	info->e_texpath = NULL;
	info->floor_color = -1;
	info->ceiling_color = -1;
	info->map_width = 0;
	info->map_height = 0;
	info->player_view = 0;
	info->player_x = 0;
	info->player_y = 0;
	initialize_map(info);
	info->s1 = NULL;
	info->s2 = NULL;
	info->door = NULL;
}

int	check_files(char *key, char *path, t_info *info)
{
	if (!ft_strcmp(key, "NO"))
		return (check_file_access(&info->n_texpath, path), 1);
	else if (!ft_strcmp(key, "WE"))
		return (check_file_access(&info->w_texpath, path), 1);
	else if (!ft_strcmp(key, "EA"))
		return (check_file_access(&info->e_texpath, path), 1);
	else if (!ft_strcmp(key, "SO"))
		return (check_file_access(&info->s_texpath, path), 1);
	else if (!ft_strcmp(key, "S1"))
		return (check_file_access(&info->s1, path), 1);
	else if (!ft_strcmp(key, "S2"))
		return (check_file_access(&info->s2, path), 1);
	else if (!ft_strcmp(key, "DO"))
		return (check_file_access(&info->door, path), 1);
	return (0);
}

void	fill_in_map_information(char *line, t_info *info)
{
	char	**splited_value;
	char	*key;
	char	*path;

	splited_value = ft_split(line, ' ');
	key = splited_value[0];
	path = splited_value[1];
	if (key == NULL || path == NULL || check_double_len(splited_value) != 2)
		exit_with_error("Invalid path informations");
	else if (!ft_strcmp(key, "F"))
		rgb_to_hex(path, &info->floor_color);
	else if (!ft_strcmp(key, "C"))
		rgb_to_hex(path, &info->ceiling_color);
	else
	{
		if (!check_files(key, path, info))
			exit_with_error("Invalid information");
	}
	free_double_arr(splited_value);
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
