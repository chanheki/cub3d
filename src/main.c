/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:32:17 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 16:32:30 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void leaks() {
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_info	info;

	program_validator(ac, av);
	parser(&info, av[1]);
	executor(&info);
	atexit(leaks);
	return (0);
}
