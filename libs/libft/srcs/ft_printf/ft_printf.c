/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 <jpedrones@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:47:35 by joapedr2          #+#    #+#             */
/*   Updated: 2022/07/17 23:56:07 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*seach_text(const char *format, char **str)
{
	int	i;

	i = 0;
	if (!format)
		return (NULL);
	while (*(format + i) && *(format + i) != '%')
		i++;
	*str = ft_substr(format, 0, i);
	return (format + i);
}

const char	*ft_types(const char *format, va_list arg, int *len, char **str)
{
	if (*format == 'c')
	{
		ft_putchar(va_arg(arg, int));
		*str = ft_strdup("");
		*len = *len + 1;
	}
	else
	{
		if (*format == 's')
			*str = ft_strdup(va_arg(arg, char *));
		else if (*format == 'd' || *format == 'i')
			*str = ft_itoa(va_arg(arg, int));
		else if (*format == 'u')
			*str = ft_utoa(va_arg(arg, unsigned int));
		else if (*format == 'x')
			*str = ft_utoa_base(va_arg(arg, unsigned int), "0123456789abcdef");
		else if (*format == 'X')
			*str = ft_utoa_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
		else if (*format == 'p')
			*str = pt_pointer(va_arg(arg, unsigned long int));
		else if (!(ft_strchr("cspdiuxX%", *format)) || *format == '%')
			*str = ft_strdup("%");
	}
	return (format + 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	char	*str;
	va_list	arg;

	len = 0;
	str = NULL;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_types((format + 1), arg, &len, &str);
		else
			format = seach_text(format, &str);
		if (!str || !format)
			str = ft_strdup("(null)");
		len += (int)ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	va_end(arg);
	return (len);
}
