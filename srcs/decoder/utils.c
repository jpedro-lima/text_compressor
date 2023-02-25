/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:13:34 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:42:19 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <decoder.h>

void	terminate(char	*str)
{
	if (errno < 0)
		perror(str);
	else
		ft_putendl_fd(str, 2);
	exit(1);
}

/**
 * @brief Função para concatenar um caractere na string 
 * com o texto descomprimido
 * 
 * @param str 
 * @param c 
 * @return wchar_t* 
 */
wchar_t	*concatc(wchar_t *str, wchar_t c)
{
	wchar_t	*text;
	int		len;
	int		i;

	i = -1;
	len = wcslen(str) + 2;
	text = (wchar_t *)calloc(len, sizeof(wchar_t));
	while (str[++i])
		text[i] = str[i];
	text[i] = c;
	return (text);
}
