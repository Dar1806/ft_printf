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

int	ft_putchar(const char c, int count)
{
	write(1, &c, 1);
	return (count);
}

int	ft_putstr(const char *str, int count)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (count);
}

int	ft_putnbr(long unsigned int nbr, int count)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', count);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else
		ft_putchar(nbr + '0', count);
}
