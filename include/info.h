/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:32:45 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/21 03:32:51 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct s_info
{
	char	*n_texpath;
	char	*s_texpath;
	char	*w_texpath;
	char	*e_texpath;

	int		floor_color;
	int		ceiling_color;

	int		map_start_idx;
	int		map_width;
	int		map_height;
	char	**map;

	char	player_view;
	int		player_x;
	int		player_y;
}			t_info;

#endif