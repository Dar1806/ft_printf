/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:20:30 by nmeunier          #+#    #+#             */
/*   Updated: 2025/11/24 11:57:03 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i++], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		count += ft_putchar('-');
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	ft_unsigned_nbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}
