/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:43:55 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 21:16:37 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "constant.h"

void	mouse_hook(t_data *cub3d)
{
	cub3d->mouse *= -1;
	if (cub3d->mouse == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_move(cub3d->window.win, GAME_WIDTH / 2, GAME_HEIGHT / 2);
		mlx_mouse_get_pos(cub3d->window.win, &(cub3d->mouse_x), \
					&(cub3d->mouse_y));
	}
	else
		mlx_mouse_show();
}

void	move_mouse(t_data *cub3d)
{
	int	x;
	int	y;
	int	dir;
	int	abs_x;

	mlx_mouse_get_pos(cub3d->window.win, &x, &y);
	if (x - cub3d->mouse_x < 0)
		dir = 0;
	else
		dir = 1;
	abs_x = abs(x - cub3d->mouse_x);
	if (abs_x >= 1)
	{
		mlx_mouse_move(cub3d->window.win, GAME_WIDTH / 2, GAME_HEIGHT / 2);
		while (abs_x > 0)
		{
			printf("%d \n", abs_x);
			if (!dir)
				rotate_left(cub3d);
			else
				rotate_right(cub3d);
			abs_x -= 25;
		}
	}
}
