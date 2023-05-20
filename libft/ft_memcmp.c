/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:57:10 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:37:54 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t			i;
	unsigned char	*unc_dest;
	unsigned char	*unc_src;

	i = 0;
	unc_dest = (unsigned char *) ptr1;
	unc_src = (unsigned char *) ptr2;
	while (i < size && unc_dest[i] == unc_src[i])
		i++;
	if (i == size)
		return (0);
	else
		return (unc_dest[i] - unc_src[i]);
}
