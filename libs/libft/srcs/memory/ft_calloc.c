/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:49:48 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/07 20:21:28 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Using malloc to create an array whose all slots are null */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (!nmemb || !size)
		return (NULL);
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	str = malloc((nmemb * size));
	if (!str)
		return (NULL);
	ft_bzero(str, (nmemb * size));
	return (str);
}
