/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:22:55 by mmarie            #+#    #+#             */
/*   Updated: 2023/03/21 13:54:16 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexa(unsigned int n, char c)
{
	int	len;

	if (!n)
		return (ft_putchar_fd('0', 1));
	len = 0;
	if (n >= 16)
	{
		len += ft_putnbrhexa(n / 16, c);
		len += ft_putnbrhexa(n % 16, c);
	}
	else
	{
		if (n <= 9)
			len += ft_putchar_fd(n + 48, 1);
		else
		{
			if (c == 'x')
				len += ft_putchar_fd(n + 87, 1);
			if (c == 'X')
				len += ft_putchar_fd(n + 55, 1);
		}
	}
	return (len);
}

int	ft_putptr(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
	{
		len += ft_putstr_fd("(nil)", 1);
		return (len);
	}
	len += ft_putstr_fd("0x", 1);
	len += ft_putnbrhexlo(n);
	return (len);
}

int	ft_putnbrhexlo(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbrhexlo(n / 16);
		len += ft_putnbrhexlo(n % 16);
	}
	else
	{
		if (n <= 9)
			len += ft_putchar_fd(n + 48, 1);
		else
			len += ft_putchar_fd(n + 87, 1);
	}
	return (len);
}

int	ft_un_putnbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_un_putnbr(n / 10);
	len += ft_putchar_fd((n % 10) + 48, 1);
	return (len);
}
