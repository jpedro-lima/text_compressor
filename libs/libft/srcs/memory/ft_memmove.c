/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:12:33 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/07 22:05:46 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* copy the value of 'str' and allocate it to 'dest' starting
from the initial pointer, and going to 'n' bytes (THE BEST)*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;

	i = -1;
	if (dest > src)
	{
		while ((int)(--n) >= 0)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
	{
		while (++i < (int)n)
			*(char *)(dest + i) = *(char *)(src + i);
	}
	return (dest);
}
