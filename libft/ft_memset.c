/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:40:17 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:37:58 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t size)
{
	size_t			i;
	unsigned char	u_value;
	unsigned char	*unc_dest;

	i = 0;
	u_value = (unsigned char) value;
	unc_dest = (unsigned char *) dest;
	while (i < size)
	{
		unc_dest[i] = u_value;
		i++;
	}
	return (dest);
}
