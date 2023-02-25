/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:29:54 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 04:16:01 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* "search" the string 'little' in the string 'big' up to slot 'n'
if found returns the pointer of the string 'little' in the
string 'big', if not found it returns NULL */
char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	lit_len;

	lit_len = ft_strlen(little);
	if (!lit_len)
		return ((char *)big);
	while (lit_len <= n && *big != '\0')
	{
		if (*big == *little)
		{
			if (!ft_strncmp(big, little, lit_len))
				return ((char *)big);
		}
		big++;
		n--;
	}
	return (NULL);
}
