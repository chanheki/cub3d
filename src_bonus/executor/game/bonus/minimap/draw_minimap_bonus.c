/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:04:32 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 19:37:22 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

void	get_ret(t_data **data)
{
	int	ret;

	ret = 8;
	while (ret > 0)
	{
		if ((*data)->x_size * ret <= GAME_WIDTH / 3
			&& (*data)->y_size * ret <= GAME_HEIGHT / 3)
		{
			(*data)->mini_ret = ret;
			return ;
		}
		ret--;
	}
	exit_with_error("Map is too big!");
}

void	draw_player(t_data *cub3d, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < cub3d->mini_ret)
	{
		dx = -1;
		while (++dx < cub3d->mini_ret)
			my_pixel_put(&(cub3d->window.img), dx + x, dy + y, color);
	}
}

void	draw_square(t_data *cub3d, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < cub3d->mini_ret)
	{
		dx = -1;
		while (++dx < cub3d->mini_ret)
			my_pixel_put(&(cub3d->window.img), dx + x, dy + y, color);
	}
}

void	draw_minimap(t_data *cub3d)
{
	int	x;
	int	y;
	int	ret;

	ret = cub3d->mini_ret;
	y = -1;
	while (++y < cub3d->y_size)
	{
		x = -1;
		while (++x < cub3d->x_size)
		{
			if ((int)cub3d->ray.pos_x == x && (int)cub3d->ray.pos_y == y)
				draw_player(cub3d, x * ret, y * ret, 0x6C3BF4);
			else if (cub3d->map[y][x] == AREA)
				draw_square(cub3d, x * ret, y * ret, 0xAEAEAE);
			else if (cub3d->map[y][x] == ENEMY)
				draw_player(cub3d, x * ret, y * ret, 0xF72F3A);
			else if (cub3d->map[y][x] >= DOOR)
				draw_player(cub3d, x * ret, y * ret, 0xFFFFFF);
			else
				draw_square(cub3d, x * ret, y * ret, 0x000000);
		}
	}
}
