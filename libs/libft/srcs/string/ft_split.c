/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:09:21 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/10 03:28:24 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* splits a string 'str' into other strings within
an array, following the divisor character 'c' */
static size_t	counter_word(const char *str, const char c)
{
	size_t	size;
	int		j;

	size = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			size++;
			j = 1;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (size);
}

static char	**tab_error(char **tab)
{
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	len = counter_word(str, c);
	tab = malloc((len + 1) * sizeof(char *));
	if (!tab || !str)
		return (tab_error(tab));
	while (*str)
	{
		if (*str != c && j < len)
		{
			i = 1;
			while (*(str + i) != c && *(str + i) != '\0')
				i++;
			tab[j++] = ft_substr(str, 0, i);
			if (*(str + i) != '\0')
				str += i;
		}
		str++;
	}
	tab[j] = NULL;
	return (tab);
}
