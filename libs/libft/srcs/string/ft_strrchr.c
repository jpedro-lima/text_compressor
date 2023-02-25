/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:59 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 04:19:32 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* looks for the last character 'c' in the string 'str',
returns the pointer to that character if found */
char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (*(str + len) == (unsigned char)c)
			return ((char *)(str + len));
	}
	return (NULL);
}
