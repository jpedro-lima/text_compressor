/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:34:24 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/17 23:32:59 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pt_pointer(unsigned long int ptr)
{
	char	*str;
	char	*temp;

	if (ptr == 0)
		return (ft_strdup("(nil)"));
	temp = ft_utoa_base(ptr, "0123456789abcdef");
	str = ft_strjoin("0x", temp);
	free(temp);
	return (str);
}
