/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:27:17 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 17:42:02 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	set_camera_x(t_ray_info *ray_info, int ind)
{
	ray_info->camera_x = 2 * ind / (double) GAME_WIDTH - 1;
	ray_info->hit = 0;
}

void	dda_logic(t_data *data, t_ray_info *ray_info)
{
	while (ray_info->hit == 0)
	{
		if (ray_info->side_dist_x < ray_info->side_dist_y)
		{
			ray_info->side_dist_x += ray_info->delta_dist_x;
			ray_info->map_x += ray_info->step_x;
			ray_info->side = 0;
		}
		else
		{
			ray_info->side_dist_y += ray_info->delta_dist_y;
			ray_info->map_y += ray_info->step_y;
			ray_info->side = 1;
		}
		if (data->map[ray_info->map_y][ray_info->map_x] == '1')
			ray_info->hit = 1;
	}
}

void	set_perp_wall_dist(t_ray ray, t_ray_info *ray_info)
{
	if (ray_info->side == 0)
		ray_info->perp_wall_dist = (ray_info->map_x
				- ray.pos_x + (1 - ray_info->step_x) / 2) / ray_info->ray_dir_x;
	else
		ray_info->perp_wall_dist = (ray_info->map_y
				- ray.pos_y + (1 - ray_info->step_y) / 2) / ray_info->ray_dir_y;
}

void	set_line_height(t_ray_info *ray_info)
{
	ray_info->line_height = (int)(GAME_HEIGHT / ray_info->perp_wall_dist);
}

void	raycasting(t_data *data)
{
	int			i;
	t_ray_info	ray_info;

	i = 0;
	while (i < GAME_WIDTH)
	{
		set_camera_x(&ray_info, i);
		dda_init(data, &ray_info);
		dda_logic(data, &ray_info);
		set_perp_wall_dist(data->ray, &ray_info);
		set_line_height(&ray_info);
		set_wall_buffer(data, ray_info, i);
		i++;
	}
}
