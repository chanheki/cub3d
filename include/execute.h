/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:37:58 by sechung           #+#    #+#             */
/*   Updated: 2023/05/29 19:45:42 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cub3d.h"
# include "math.h"

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_ray;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[GAME_HEIGHT][GAME_WIDTH];
}				t_window;

typedef struct s_texture
{
	int	*texture;
	int	height;
	int	width;
}				t_texture;

typedef struct s_textures
{
	t_texture		north_wall;
	t_texture		south_wall;
	t_texture		east_wall;
	t_texture		west_wall;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}				t_textures;

typedef struct s_data
{
	t_ray		ray;
	t_window	window;
	t_textures	textures;
	char		**map;
	t_bool		press[256];
	int			mini_ret;
	int			x_size;
	int			y_size;
	int			mouse;
	int			mouse_x;
	int			mouse_y;
}				t_data;

typedef struct s_ray_info
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x;
	int		step_y;
	int		hit;

	int		side;

	double	perp_wall_dist;
	int		line_height;
}				t_ray_info;

typedef struct s_wall_info
{
	int			draw_start;
	int			draw_end;
	t_texture	*texture;
	int			tex_x;
}				t_wall_info;

void	executor(t_info *info);
void	init_game_data(t_data *data, t_info *info);
void	init_texture(t_texture *texture, char *texture_path, void *mlx);
int		game(t_data *data);
void	raycasting(t_data *data);
void	dda_init(t_data *data, t_ray_info *ray_info);
void	set_wall_buffer(t_data *data, t_ray_info ray_info, int i);
int		finish_game(int num);
int		press_events(int key_num, t_data *data);
int		release_events(int key_num, t_data *data);
int		actions(t_data *data);
void	up_action(t_data *data);
void	down_action(t_data *data);
void	right_action(t_data *data);
void	left_action(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);
#endif
