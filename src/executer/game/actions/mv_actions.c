/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:23:13 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 17:23:15 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	mv_action(t_data *data, double n_pos_x, double n_pos_y)
{
	if (data->map[(int)data->ray.pos_y][(int)n_pos_x] != '1')
		data->ray.pos_x = n_pos_x;
	if (data->map[(int)n_pos_y][(int)data->ray.pos_x] != '1')
		data->ray.pos_y = n_pos_y;
}

void	up_action(t_data *data)
{
	double	n_pos_x;
	double	n_pos_y;

	n_pos_x = data->ray.pos_x + data->ray.dir_x * MOVE_SPEED;
	n_pos_y = data->ray.pos_y + data->ray.dir_y * MOVE_SPEED;
	mv_action(data, n_pos_x, n_pos_y);
}

void	down_action(t_data *data)
{
	double	n_pos_x;
	double	n_pos_y;

	n_pos_x = data->ray.pos_x - data->ray.dir_x * MOVE_SPEED;
	n_pos_y = data->ray.pos_y - data->ray.dir_y * MOVE_SPEED;
	mv_action(data, n_pos_x, n_pos_y);
}

void	left_action(t_data *data)
{
	double	n_pos_x;
	double	n_pos_y;

	n_pos_x = data->ray.pos_x + data->ray.dir_y * MOVE_SPEED;
	n_pos_y = data->ray.pos_y - data->ray.dir_x * MOVE_SPEED;
	mv_action(data, n_pos_x, n_pos_y);
}

void	right_action(t_data *data)
{
	double	n_pos_x;
	double	n_pos_y;

	n_pos_x = data->ray.pos_x - data->ray.dir_y * MOVE_SPEED;
	n_pos_y = data->ray.pos_y + data->ray.dir_x * MOVE_SPEED;
	mv_action(data, n_pos_x, n_pos_y);
}
