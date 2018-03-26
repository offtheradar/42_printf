/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:53 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/26 16:14:39 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void	ft_parse_format_spec(char **str, int *done, va_list arg)
{
	
}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int done;

	done = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			find_out_what_do(&format, &done, arg);
		else
		{
			ft_putchar(*format);
			done++;
		}
		format++;
	}
	va_end(arg);
	return (done);
}
