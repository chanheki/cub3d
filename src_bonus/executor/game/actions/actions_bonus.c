/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:21:43 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 17:22:09 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	default_action(t_data *data)
{
	(void) data;
}

void	esc_action(t_data *data)
{
	(void) data;
	exit(0);
}

void	do_actions(void (*events[])(t_data*), t_data *data)
{
	int	key_num;

	key_num = 0;
	while (key_num < 256)
	{
		if (data->press[key_num] == TRUE)
			events[key_num](data);
		key_num++;
	}
}

void	init_actions(void (*events[])(t_data*))
{
	int	ind;

	ind = 0;
	while (ind < 256)
		events[ind++] = default_action;
	events[ESC] = esc_action;
	events[DOWN] = down_action;
	events[UP] = up_action;
	events[RIGHT] = right_action;
	events[LEFT] = left_action;
	events[R_LEFT] = rotate_left;
	events[R_RIGHT] = rotate_right;
}

int	actions(t_data *data)
{
	void	(*events[256])(t_data*);

	init_actions(events);
	do_actions(events, data);
	return (0);
}
