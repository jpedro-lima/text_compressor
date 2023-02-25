/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:11:56 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 05:07:12 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* apara a string 'set' do começo e do fim da string 's1' */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i]) != 0)
		i--;
	return (ft_substr(s1, 0, (i + 1)));
}
