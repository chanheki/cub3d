/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:31:50 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 15:18:32 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	map_walled_off(int h, int w, t_info *info)
{
	if (info->map[h][w] == ' ' || info->map[h][w] == '\n')
		exit_with_error("Not walled off");
}

void	player_position(int h, int w, t_info *info)
{
	if (info->map[h][w] == 'N' || info->map[h][w] == 'E'
		|| info->map[h][w] == 'W' || info->map[h][w] == 'S')
	{
		if (info->player_view != 0)
			exit_with_error("Detecting Duplicate Players");
		info->player_view = info->map[h][w];
		info->visited[h][w] = '1';
		info->player_x = w;
		info->player_y = h;
	}
}

void	map_dfs(int h, int w, t_info *info)
{
	int			i;

	i = 0;
	map_walled_off(h, w, info);
	player_position(h, w, info);
	info->visited[h][w] = '1';
	while (i < 4)
	{
		if (map_dfs_checker(i, &h, &w, info))
			map_dfs(h, w, info);
		i++;
	}
}

int	map_dfs_checker(int i, int *h, int *w, t_info *info)
{
	const int	dx[4] = {0, -1, 1, 0};
	const int	dy[4] = {-1, 0, 0, 1};
	int			nx;
	int			ny;

	nx = *(w) + dx[i];
	ny = *(h) + dy[i];
	if (nx >= 0 && ny >= 0 && ny < info->map_height
		&& info->visited[ny][nx] != '1'
		&& (info->map[ny][nx] != '1'))
	{
		*h = ny;
		*w = nx;
		return (1);
	}
	return (0);
}
