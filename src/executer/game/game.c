/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:31:24 by sechung           #+#    #+#             */
/*   Updated: 2023/05/17 22:01:05 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	floor_ceiling(t_window *window, t_textures textures)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < GAME_HEIGHT)
	{
		while (j < GAME_WIDTH)
		{
			if (i >= GAME_HEIGHT / 2)
				window->buf[i][j] = textures.floor_color;
			else
				window->buf[i][j] = textures.ceiling_color;
			j++;
		}
		i++;
		j = 0;
	}
}

void	draw_window(t_window window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < GAME_HEIGHT)
	{
		while (j < GAME_WIDTH)
		{
			window.img.data[i * GAME_WIDTH + j] = window.buf[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(window.mlx, window.win, window.img.img, 0, 0);
}

void	correction_position(t_ray *ray)
{
	while (ray->pos_x - (double)((int) ray->pos_x) >= 0.99999)
		ray->pos_x += 0.00001;
	while (ray->pos_x - (double)((int) ray->pos_x) <= 0.00001)
		ray->pos_x += 0.00001;
	while (ray->pos_y - (double)((int) ray->pos_y) >= 0.99999)
		ray->pos_y += 0.00001;
	while (ray->pos_y - (double)((int) ray->pos_y) <= 0.00001)
		ray->pos_y += 0.00001;
}

int	game(t_data *data)
{
	actions(data);
	correction_position(&data->ray);
	floor_ceiling(&data->window, data->textures);
	raycasting(data);
	draw_window(data->window);
	return (0);
}
