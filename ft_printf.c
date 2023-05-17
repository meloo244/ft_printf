/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:46:43 by mmarie            #+#    #+#             */
/*   Updated: 2023/03/21 13:54:14 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
		len += ft_putptr((unsigned long)va_arg(args, unsigned long));
	if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		len += ft_un_putnbr(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_putnbrhexa(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		final_len;
	va_list	args;

	final_len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			final_len += check(str[i + 1], args);
			i++;
		}
		else
			final_len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (final_len);
}
