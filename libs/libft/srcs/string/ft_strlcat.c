/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:02:02 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 03:45:43 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* concatenate string 'src' into string 'dest' and return array size */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	j = 0;
	if (dst_len < size - 1 && size > 0)
	{
		while ((dst_len + j) < size - 1 && *(src + j) != '\0')
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	if (size <= dst_len)
		return (src_len + size);
	return (dst_len + src_len);
}
