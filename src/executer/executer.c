/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:22:57 by sechung           #+#    #+#             */
/*   Updated: 2023/05/20 20:19:15 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	calloc_data(t_data **data)
{
	*data = ft_calloc(1, sizeof(t_data));
	malloc_check(*data);
}

void	executer(t_info *info)
{
	t_data	*data;

	calloc_data(&data);
	init_game_data(data, info);
	mlx_loop_hook(data->window.mlx, &game, data);
	mlx_hook(data->window.win, X_EVENT_CLOSE_BUTTON, 0, finish_game, 0);
	mlx_hook(data->window.win, X_EVENT_KEY_PRESS, 0, press_events, data);
	mlx_hook(data->window.win, X_EVENT_KEY_RELEASE, 0, release_events, data);
	mlx_loop(data->window.mlx);
}
