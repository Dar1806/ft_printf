/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:56:00 by nmeunier          #+#    #+#             */
/*   Updated: 2025/11/26 10:56:00 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexa_low_long(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbrhexa_low_long(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putnbrhexa_low(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbrhexa_low(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putnbrhexa_up(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbrhexa_up(n / 16);
	count += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}

int	ft_voidhexa(void *adress)
{
	unsigned long	value;

	if (adress == 0)
		return (write(1, "(nil)", 5));
	value = (unsigned long)adress;
	return (write(1, "0x", 2) + ft_putnbrhexa_low_long(value));
}
