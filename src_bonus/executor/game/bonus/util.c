/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:10:54 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/29 17:13:04 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "bonus.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = (char *)img->data + (y * img->size_l
			+ x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
