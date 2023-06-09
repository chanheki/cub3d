/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:23:24 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 18:19:57 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include <stdio.h>
# include <fcntl.h>

/* check */
void	check_file_access(char **info_path, char *value);
int		check_double_len(char **arr);
int		is_just_new_line(char *line);
int		staging_map_checker(t_info *info);
void	map_visited_check(t_info *info);

/* dfs */
void	map_walled_off(int h, int w, t_info *info);
void	player_position(int h, int w, t_info *info);
void	map_dfs(int h, int w, t_info *info);
int		map_dfs_checker(int i, int *h, int *w, t_info *info);

/* insert */
void	initialize_info(t_info *info);
void	fill_in_map_information(char *line, t_info *info);
char	*map_newline_pushing(int fd);

/* parse */
void	parser(t_info *info, char *path);
void	map_board_parsing(int fd, t_info *info);

/* rgb */
void	rgb_to_hex(char *rgb, int *rgb_path);
void	rgb_validator(int r, int g, int b, char **rgb_arr);

/* utils */
void	free_double_arr(char **arr);
int		file_open(char *path);
int		ft_strlen_index(char *str);
void	dup_map(t_info *info);

/* validator */
void	map_info_validator(t_info *info);
void	map_components_validator(char *str);
void	map_parsing_validator(int fd, t_info *info);
void	map_board_validator(t_info *info);
void	check_rgb_validator(const char *str);
#endif
