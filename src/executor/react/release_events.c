/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:35:17 by sechung           #+#    #+#             */
/*   Updated: 2023/05/13 17:35:18 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	release_events(int key_num, t_data *data)
{
	if (key_num < 256)
		data->press[key_num] = FALSE;
	return (0);
}
