/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:42:00 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 03:33:12 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a duplicate of the string 'str' and returns it */
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
