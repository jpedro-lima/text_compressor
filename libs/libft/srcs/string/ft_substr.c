/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:35:57 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 04:56:03 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* creates a new string based on the string 's' */
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
