/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:29:24 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:38:16 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	size_t	s_size;

	c_c = (char) c;
	s_size = ft_strlen(s);
	while (s_size != 0 && *(s + s_size) != c_c)
		s_size--;
	if (s[s_size] == c_c)
		return ((char *) s + s_size);
	return (0);
}
