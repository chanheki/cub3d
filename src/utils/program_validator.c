/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:32:39 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 16:32:40 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	program_validator(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		exit_with_error("no map file error");
	else if (ac != 2)
		exit_with_error("too many arguments error");
	else
	{
		while (av[1][i])
			i++;
		if (i < 5)
			exit_with_error("invalid map file error");
		if (ft_strcmp(av[1] + i - 4, ".cub") != 0)
			exit_with_error("invalid cub file error");
	}
}
