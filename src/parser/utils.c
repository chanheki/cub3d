/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:32:00 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 15:17:03 by chanheki         ###   ########.fr       */
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
