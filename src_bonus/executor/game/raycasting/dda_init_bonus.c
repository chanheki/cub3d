/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:24:17 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 17:27:07 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	init_map_pos(t_ray ray, t_ray_info *ray_info)
{
	ray_info->map_x = (int) ray.pos_x;
	ray_info->map_y = (int) ray.pos_y;
}

void	set_ray_dir(t_ray ray, t_ray_info *ray_info)
{
	ray_info->ray_dir_x = ray.dir_x + ray.plane_x * ray_info->camera_x;
	ray_info->ray_dir_y = ray.dir_y + ray.plane_y * ray_info->camera_x;
}

void	set_delta_dist(t_ray_info *ray_info)
{
	ray_info->delta_dist_x = sqrt(1
			+ (ray_info->ray_dir_y * ray_info->ray_dir_y)
			/ (ray_info->ray_dir_x * ray_info->ray_dir_x));
	ray_info->delta_dist_y = sqrt(1
			+ (ray_info->ray_dir_x * ray_info->ray_dir_x)
			/ (ray_info->ray_dir_y * ray_info->ray_dir_y));
}

void	set_side_dist(t_ray ray, t_ray_info *ray_info)
{
	if (ray_info->ray_dir_x < 0)
	{
		ray_info->step_x = -1;
		ray_info->side_dist_x = (ray.pos_x
				- ray_info->map_x) * ray_info->delta_dist_x;
	}
	else
	{
		ray_info->step_x = 1;
		ray_info->side_dist_x = (ray_info->map_x + 1.0
				- ray.pos_x) * ray_info->delta_dist_x;
	}
	if (ray_info->ray_dir_y < 0)
	{
		ray_info->step_y = -1;
		ray_info->side_dist_y = (ray.pos_y
				- ray_info->map_y) * ray_info->delta_dist_y;
	}
	else
	{
		ray_info->step_y = 1;
		ray_info->side_dist_y = (ray_info->map_y + 1.0
				- ray.pos_y) * ray_info->delta_dist_y;
	}
}

void	dda_init(t_data *data, t_ray_info *ray_info)
{
	init_map_pos(data->ray, ray_info);
	set_ray_dir(data->ray, ray_info);
	set_delta_dist(ray_info);
	set_side_dist(data->ray, ray_info);
}
