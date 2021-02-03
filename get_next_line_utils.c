/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiwata <hiwata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:04:12 by hiwata            #+#    #+#             */
/*   Updated: 2020/11/16 16:27:56 by hiwata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i++;
	while (i)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
		i--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t			len;
	char			*p;
	char			*s_cpy;

	len = 0;
	while (s1[len] != '\0')
		len++;
	s_cpy = malloc(sizeof(char) * (len + 1));
	if (!s_cpy)
	{
		free(s_cpy);
		return (NULL);
	}
	else
	{
		p = s_cpy;
		while (*s1)
			*p++ = *s1++;
		*p = '\0';
		return (s_cpy);
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			d_len;
	size_t			s_len;
	size_t			i;

	d_len = 0;
	while (dst[d_len])
		d_len++;
	s_len = 0;
	while (src[s_len])
		s_len++;
	i = 0;
	if (d_len < dstsize)
	{
		while (dstsize - d_len - 1 > i && src[i])
		{
			dst[d_len + i] = src[i];
			i++;
		}
	}
	dst[i + d_len] = '\0';
	if (d_len >= dstsize)
		return (s_len + dstsize);
	return (s_len + d_len);
}

void	ft_strlcpy(char *dest, char *src, size_t size)
{
	char			*pdst;
	const char		*psrc;
	size_t			i;

	pdst = dest;
	psrc = src;
	i = size;
	if (i != 0)
	{
		while (--i != 0)
		{
			if ((*pdst++ = *psrc++) == '\0')
				break ;
		}
	}
	if (i == 0)
	{
		if (size != 0)
			*pdst = '\0';
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	size_t			total_len;
	char			*result;

	if (!s1 && !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	total_len = s1_len + s2_len;
	if (!(result = malloc(total_len + 1)))
	{
		free(result);
		return (NULL);
	}
	ft_strlcpy(result, (char *)s1, s1_len + 1);
	ft_strlcat(result, s2, total_len + 1);
	return (result);
}
