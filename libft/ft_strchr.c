/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:19:39 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:38:05 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	size_t	i;

	i = 0;
	c_c = (char) c;
	while (s[i] != c_c && s[i] != 0)
		i++;
	if (s[i] == c_c)
		return ((char *) s + i);
	return (0);
}
