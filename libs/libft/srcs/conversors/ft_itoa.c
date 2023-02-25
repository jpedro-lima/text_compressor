/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:06:23 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/07 20:36:07 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert integer number to string */
static size_t	len_mal(unsigned int n, int flag)
{
	size_t	i;

	i = 1;
	while (n >= 10 && i++)
		n /= 10;
	if (flag)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				flag;
	size_t			len;
	unsigned int	nc;

	nc = n;
	flag = n < 0;
	if (flag)
		nc = -nc;
	len = len_mal(nc, flag) + 1;
	nbr = (char *)malloc(len * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[--len] = '\0';
	if (n == 0)
		nbr[--len] = '0';
	while (nc)
	{
		nbr[--len] = (nc % 10) + '0';
		nc /= 10;
	}
	if (flag)
		nbr[--len] = '-';
	return (nbr);
}
