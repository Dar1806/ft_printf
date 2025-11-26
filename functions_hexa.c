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

int	ft_putnbrhexa_low(unsigned long n, int count)
{
	if (n >= 16)
		count += ft_putnbrhexa_low(n / 16, count);
	ft_putchar("0123456789abcdef"[n % 16], 1);
	count++;
}

int	ft_voidhexa(const void *adress, int count)
{
	int	i;

	i = 0;
	if (adress == 0)
		write(1, "(nil)", 5);
	return (write(1, "0x", 2) + ft_putnbrhexa_low(adress));
}
