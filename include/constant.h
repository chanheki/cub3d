/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:37:24 by sechung           #+#    #+#             */
/*   Updated: 2023/05/29 22:10:09 by chanheki         ###   ########.fr       */
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
# define BUFFER_SIZE 42

# define GAME_HEIGHT 720
# define GAME_WIDTH 1080

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
# define KEY_DOOR 49
# define KEY_ONE 18

# define MAP_MAXHEIGHT 1000
# define MAP_MAXWIDTH 1000

/* bonus */
# define AREA	'0'
# define WALL	'1'
# define ENEMY	'2'
# define DOOR	'3'
# define W		'W'
# define S		'S'
# define E		'E'
# define D		'D'

#endif
