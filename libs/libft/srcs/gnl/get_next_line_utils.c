/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:24:46 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/11 23:34:00 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*strc;
	size_t	len;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	strc = malloc(len * sizeof(char));
	if (!strc)
		return (NULL);
	while (*(str + i) != '\0')
	{
		*(strc + i) = *((char *)str + i);
		i++;
	}
	*(strc + i) = '\0';
	return (strc);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	while (*(s + start + n) != '\0' && n < len)
		n++;
	sbstr = malloc((n + 1) * sizeof(char));
	if (!sbstr)
		return (NULL);
	while (i < len && *(s + start) != '\0')
	{
		*(sbstr + i) = *((char *)s + start);
		start++;
		i++;
	}
	*(sbstr + i) = '\0';
	return (sbstr);
}
