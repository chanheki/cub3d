/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:31:24 by sechung           #+#    #+#             */
/*   Updated: 2023/05/29 21:14:22 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "bonus.h"

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

void	draw_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < GAME_HEIGHT)
	{
		while (j < GAME_WIDTH)
		{
			data->window.img.data[i * GAME_WIDTH + j] = data->window.buf[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win, \
						data->window.img.img, 0, 0);
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
	if (data->mouse == 1)
		move_mouse(data);
	correction_position(&data->ray);
	floor_ceiling(&data->window, data->textures);
	raycasting(data);
	draw_window(data);
	return (0);
}
