/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:31:45 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 21:58:34 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_file_access(char **info_path, char *value)
{
	int	fd;
	int	end;

	if (*info_path != NULL)
		exit_with_error("Duplicate File Check");
	*info_path = ft_strdup(value);
	end = ft_strlen_index(*info_path);
	info_path[0][end - 1] = '\0';
	fd = open(*info_path, O_RDONLY);
	if (fd == -1)
		exit_with_error("Inaccessible file");
	close(fd);
}

int	check_double_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_just_new_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

int	staging_map_checker(t_info *info)
{
	if (info->n_texpath == 0)
		return (0);
	if (info->s_texpath == 0)
		return (0);
	if (info->w_texpath == 0)
		return (0);
	if (info->e_texpath == 0)
		return (0);
	if (info->floor_color == -1)
		return (0);
	if (info->ceiling_color == -1)
		return (0);
	return (1);
}

void	map_visited_check(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_height)
	{
		if (ft_strchr(info->visited[i], '0'))
		{
			printf("%s \n", info->visited[i]);
			exit_with_error("There are still unprocessed zeros left.");
		}
		i++;
	}
}
