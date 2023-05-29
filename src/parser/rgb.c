/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:14:13 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 15:14:35 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_rgb_validator(const char *str)
{
	int	i;

	i = 0;
	while (str || str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ',')
			break ;
		i++;
	}
	if (str[i] != '\n')
		exit_with_error("Incoming non-numeric values");
}

void	rgb_validator(int r, int g, int b, char **rgb_arr)
{
	int	i;

	i = -1;
	if (check_double_len(rgb_arr) != 3)
		exit_with_error("num of RGB value is not valid");
	if (ft_strlen(rgb_arr[0]) > 3 || ft_strlen(rgb_arr[1]) > 3
		|| ft_strlen(rgb_arr[2]) > 4)
		exit_with_error("RGB value is not valid");
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_with_error("RGB value is not valid");
}

void	rgb_to_hex(char *rgb, int *rgb_path)
{
	int				r;
	int				g;
	int				b;
	char			**rgb_arr;

	if (*rgb_path != -1)
		exit_with_error("Duplicate RGB value");
	check_rgb_validator(rgb);
	rgb_arr = ft_split(rgb, ',');
	if (!rgb_arr[0] || !rgb_arr[1] || !rgb_arr[2])
		exit_with_error("RGB Empty values");
	r = ft_atoi(rgb_arr[0]);
	g = ft_atoi(rgb_arr[1]);
	b = ft_atoi(rgb_arr[2]);
	rgb_validator(r, g, b, rgb_arr);
	free_double_arr(rgb_arr);
	*rgb_path = ((r << 16) + (g << 8) + b);
}
