/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:31:56 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 15:17:10 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	line_to_map(int *h, char *line, t_info *info)
{
	int		w;

	w = 1;
	while (line && !(line[w - 1] == 0))
	{
		info->map[*h][w] = line[w - 1];
		w++;
		if (w > MAP_MAXWIDTH - 1)
			exit_with_error("Map size is too large");
	}
	*(h) += 1;
	if (*(h) > MAP_MAXHEIGHT)
		exit_with_error("Map size is too large");
	if (info->map_width < w)
		info->map_width = w;
}

void	map_board_parsing(int fd, t_info *info)
{
	char	*line;
	int		h;

	line = map_newline_pushing(fd);
	h = 1;
	while (1)
	{
		map_components_validator(line);
		if (line == NULL)
			break ;
		else if (is_just_new_line(line))
		{
			free(line);
			exit_with_error("Empty lines can't come in.");
			continue ;
		}
		else
			line_to_map(&h, line, info);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	info->map_height = h;
	dup_map(info);
}

void	map_info_validator(t_info *info)
{
	if (info->n_texpath == NULL
		|| info->s_texpath == NULL
		|| info->w_texpath == NULL
		|| info->e_texpath == NULL
		|| info->floor_color == -1
		|| info->ceiling_color == -1
		|| info->map_width == 0
		|| info->map_height == 0
		|| info->player_view == 0
		|| info->player_x == 0
		|| info->player_y == 0)
		exit_with_error("Value entry is not progressing");
}

void	parser(t_info *info, char *path)
{
	int	fd;

	fd = file_open(path);
	initialize_info(info);
	map_parsing_validator(fd, info);
	map_board_parsing(fd, info);
	close (fd);
	map_board_validator(info);
	map_info_validator(info);
}
