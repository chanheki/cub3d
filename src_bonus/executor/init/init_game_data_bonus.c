/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:32:15 by sechung           #+#    #+#             */
/*   Updated: 2023/05/29 19:54:20 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "bonus.h"

void	dir_and_plane_setting(t_ray *ray, char player_view)
{
	if (player_view == 'N')
	{
		ray->dir_y = -1.0;
		ray->plane_x = 0.66;
	}
	else if (player_view == 'S')
	{
		ray->dir_y = 1.0;
		ray->plane_x = -0.66;
	}
	else if (player_view == 'W')
	{
		ray->dir_x = -1.0;
		ray->plane_y = -0.66;
	}
	else
	{
		ray->dir_x = 1.0;
		ray->plane_y = 0.66;
	}
}

void	init_ray(t_ray *ray, t_info *info)
{
	ray->pos_x = info->player_x;
	ray->pos_y = info->player_y;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->plane_x = 0.0;
	ray->plane_y = 0.0;
	dir_and_plane_setting(ray, info->player_view);
}

void	init_textures(t_data *data, t_info *info)
{
	data->textures.ceiling_color = info->ceiling_color;
	data->textures.floor_color = info->floor_color;
	init_texture(&data->textures.north_wall, info->n_texpath, data->window.mlx);
	init_texture(&data->textures.south_wall, info->s_texpath, data->window.mlx);
	init_texture(&data->textures.east_wall, info->e_texpath, data->window.mlx);
	init_texture(&data->textures.west_wall, info->w_texpath, data->window.mlx);
}

void	init_window(t_window *window)
{
	window->mlx = mlx_init();
	null_check(window->mlx, "mlx init failed");
	window->img.img = mlx_new_image(window->mlx, GAME_WIDTH, GAME_HEIGHT);
	null_check(window->img.img, "mlx new image failed");
	window->img.data = (int *)mlx_get_data_addr(window->img.img,
			&window->img.bpp, &window->img.size_l, &window->img.endian);
	null_check(window->img.data, "mlx get data addr failed");
	window->win = mlx_new_window(window->mlx, GAME_WIDTH, GAME_HEIGHT, "mlx");
}

void	init_game_data(t_data *data, t_info *info)
{
	int	i;

	i = 0;
	init_ray(&data->ray, info);
	init_window(&data->window);
	init_textures(data, info);
	data->map = calloc(sizeof(char *), MAP_MAXHEIGHT);
	while (i < info->map_height)
	{
		data->map[i] = ft_strdup(info->map[i]);
		i++;
	}
	data->x_size = info->map_width;
	data->y_size = info->map_height;
	get_ret(&data);
	data->mouse = -1;
	data->mouse_x = 0;
	data->mouse_y = 0;
}
