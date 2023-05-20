/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:37:24 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 18:02:46 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

# define STDERR 2

# define GAME_HEIGHT 720
# define GAME_WIDTH 1080

# define WALL 1

# define MOVE_SPEED 0.015
# define ROT_SPEED 0.015

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_CLOSE_BUTTON 17

# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define R_LEFT 123
# define R_RIGHT 124

#endif
