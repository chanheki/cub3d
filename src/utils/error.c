/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:35:39 by sechung           #+#    #+#             */
/*   Updated: 2023/05/15 16:25:16 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_error(char *msg)
{
	ft_putstr_fd("Cub3D: program exit by ", STDERR);
	ft_putstr_fd(msg, STDERR);
	ft_putstr_fd(" Error\n", STDERR);
	exit(1);
}

void	malloc_check(void *value)
{
	if (!value)
		exit_with_error("malloc failed");
}

void	null_check(void *value, char *msg)
{
	if (!value)
		exit_with_error(msg);
}
