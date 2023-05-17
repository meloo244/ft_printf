/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel <mel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:20:24 by mmarie            #+#    #+#             */
/*   Updated: 2023/03/21 14:42:36 by mel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	len;

	len = 1;
	write(fd, &c, 1);
	return (len);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!str)
	{
		len = ft_putstr_fd("(null)", 1);
		return (len);
	}
	while (str[i])
	{
		len += ft_putchar_fd(str[i], fd);
		i++;
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(fd, "-2147483648", 11);
		return (len);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			len += write(fd, "-", 1);
		}
		if (n > 9)
			len += ft_putnbr_fd(n / 10, fd);
		len += ft_putchar_fd((n % 10) + 48, fd);
	}
	return (len);
}
