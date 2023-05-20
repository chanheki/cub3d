/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:27:32 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 17:42:34 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	set_wall_draw_point(t_ray_info ray_info, t_wall_info *wall_info)
{
	wall_info->draw_start = -1 * ray_info.line_height / 2 + GAME_HEIGHT / 2;
	wall_info->draw_end = ray_info.line_height / 2 + GAME_HEIGHT / 2;
	if (wall_info->draw_start < 0)
		wall_info->draw_start = 0;
	if (wall_info->draw_end >= GAME_HEIGHT)
		wall_info->draw_end = GAME_HEIGHT - 1;
}

void	set_wall_texture(
			t_textures *textures,
			t_ray_info ray_info,
			t_wall_info *wall_info)
{
	if (ray_info.side == 0)
	{
		if (ray_info.ray_dir_x >= 0)
			wall_info->texture = &textures->east_wall;
		else
			wall_info->texture = &textures->west_wall;
	}
	else
	{
		if (ray_info.ray_dir_y >= 0)
			wall_info->texture = &textures->south_wall;
		else
			wall_info->texture = &textures->north_wall;
	}
}

void	set_tex_x(t_ray ray, t_ray_info ray_info, t_wall_info *wall_info)
{
	double	wall_x;

	if (ray_info.side == 0)
		wall_x = ray.pos_y + ray_info.perp_wall_dist * ray_info.ray_dir_y;
	else
		wall_x = ray.pos_x + ray_info.perp_wall_dist * ray_info.ray_dir_x;
	wall_x -= floor(wall_x);
	wall_info->tex_x = (int)(wall_x * (double) wall_info->texture->width);
	if ((ray_info.side == 0 && ray_info.ray_dir_x < 0)
		|| (ray_info.side == 1 && ray_info.ray_dir_y >= 0))
		wall_info->tex_x = wall_info->texture->width - wall_info->tex_x - 1;
}

void	set_wall_buffer_logic(
			t_window *window,
			t_ray_info ray_info,
			t_wall_info *wall_info,
			int i)
{
	double	step;
	double	tex_pos;
	int		j;
	int		tex_y;
	int		color;

	step = (double)(wall_info->texture->height) / ray_info.line_height;
	tex_pos = (wall_info->draw_start
			- GAME_HEIGHT / 2 + ray_info.line_height / 2) * step;
	j = wall_info->draw_start;
	while (j <= wall_info->draw_end)
	{
		tex_y = (int) tex_pos;
		if (tex_y >= wall_info->texture->height)
			tex_y = wall_info->texture->height - 1;
		color = wall_info->texture->texture[wall_info->texture->width
			* tex_y + wall_info->tex_x];
		window->buf[j][i] = color;
		tex_pos += step;
		j++;
	}
}

void	set_wall_buffer(t_data *data, t_ray_info ray_info, int i)
{
	t_wall_info	wall_info;

	set_wall_draw_point(ray_info, &wall_info);
	set_wall_texture(&data->textures, ray_info, &wall_info);
	set_tex_x(data->ray, ray_info, &wall_info);
	set_wall_buffer_logic(&data->window, ray_info, &wall_info, i);
}
