/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:31:56 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 17:59:48 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	map_board_parsing(int fd, t_info *info)
{
	char	*line;
	int		h;

	line = map_newline_pushing(fd);
	h = -1;
	info->map = (char **)ft_calloc(sizeof(char *), MAP_MAXHEIGHT);
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
			info->map[++h] = line;
		if (h > MAP_MAXHEIGHT)
			exit_with_error("Map size is too large");
		line = get_next_line(fd);
	}
	info->map_height = h;
	double_arr_dup(info);
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
}
