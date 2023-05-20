/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:06:03 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/21 03:43:06 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "info.h"
# include "constant.h"
# include "execute.h"
# include "parse.h"

/* utils/error */
void	exit_with_error(char *msg);
void	malloc_check(void *value);
void	null_check(void *value, char *msg);

/* utils/program_validator */
void	program_validator(int ac, char **av);
#endif
