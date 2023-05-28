/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:32:03 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 20:01:01 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	map_components_validator(char *str)
{
	while (str && *str)
	{
		if (!(*str == '1' || *str == '0'
				|| *str == 'N' || *str == 'E'
				|| *str == 'W' || *str == 'S'
				|| *str == ' ' || *str == '\n'))
			exit_with_error("Invalid map components");
		str++;
	}
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

void	map_board_validator(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map_height - 1)
	{
		j = 0;
		while (info->map[i][j] != '\n')
		{
			if (info->visited[i][j] != '1' && (info->map[i][j] == '0'
			|| info->map[i][j] == 'N' || info->map[i][j] == 'E'
			|| info->map[i][j] == 'W' || info->map[i][j] == 'S'))
				map_dfs(i, j, info);
			j++;
		}
		i++;
	}
	map_visited_check(info);
}
