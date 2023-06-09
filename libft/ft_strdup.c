/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:41:56 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:38:07 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	copy = malloc(sizeof(char) * (size + 1));
	if (copy == 0)
		return (0);
	while (i < size)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
