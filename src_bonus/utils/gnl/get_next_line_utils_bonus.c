/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:23:16 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/28 16:07:32 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (*s++)
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	size = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (size);
	while (*src && (dstsize--) != 1)
		*dst++ = *src++;
	*dst = 0;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	index;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	while (dstlen + index + 1 < dstsize && *(src + index))
	{
		*(dst + dstlen + index) = *(src + index);
		index++;
	}
	*(dst + dstlen + index) = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	size_t		total_length;

	if (!s1 || !s2)
		return (NULL);
	total_length = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = (char *)malloc(sizeof(char) * total_length);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, total_length);
	ft_strlcat(result, s2, total_length);
	return (result);
}

char	*ft_strndup(const char *src, int start, int num)
{
	char	*p;
	int		i;
	int		j;

	p = (char *)(malloc(sizeof(char) * (sizeof(char) * (num + 1))));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (src[i] && j < num)
	{
		p[i] = src[start + j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
