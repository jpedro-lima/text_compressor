/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:06:23 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/15 15:27:19 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert unsigned integer number to string */
static size_t	len_mal(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n >= 10 && i++)
		n /= 10;
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char			*nbr;
	size_t			len;

	len = len_mal(n) + 1;
	nbr = (char *)malloc(len * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[--len] = '\0';
	if (n == 0)
		nbr[--len] = '0';
	while (n)
	{
		nbr[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}
