/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:20:52 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:37:56 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*c_dest;
	char	*c_src;

	if (!dest)
		(void)(*((char *) dest));
	if (!src)
		(void)(*((char *) src));
	if (dest == src)
		return (dest);
	c_dest = (char *) dest;
	c_src = (char *) src;
	i = 0;
	while (i < size)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
