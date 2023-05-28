/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:32:00 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 18:27:13 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	file_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error("File open");
	return (fd);
}

int	ft_strlen_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	dup_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_MAXHEIGHT)
	{
		j = 0;
		while (j < MAP_MAXWIDTH)
		{
			info->visited[i][j] = info->map[i][j];
			j++;
		}
		i++;
	}
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
