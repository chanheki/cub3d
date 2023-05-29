/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:28:40 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 21:12:49 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "execute.h"

void	draw_minimap(t_data *cub3d);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	get_ret(t_data **data);
void	mouse_hook(t_data *cub3d);
void	move_mouse(t_data *cub3d);
#endif