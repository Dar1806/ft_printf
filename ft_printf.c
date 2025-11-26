/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:20:41 by nmeunier          #+#    #+#             */
/*   Updated: 2025/11/24 14:32:03 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char *str, int i, va_list *args)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (str[i] == 'p')
		count += ft_voidhexa(va_arg(*args, void *));
	else if (str[i] == 'd')
		count += ft_putnbr(va_arg(*args, int));
	else if (str[i] == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (str[i] == 'u')
		count += ft_unsigned_nbr(va_arg(*args, unsigned int));
	else if (str[i] == 'x')
		count += ft_putnbrhexa_low(va_arg(*args, int));
	else if (str[i] == 'X')
		count += ft_putnbrhexa_up(va_arg(*args, int));
	else if (str[i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += check(str, i, &args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	result;

	result = 0;
	result = ft_printf("%c - %s - %p %d - %i - %u - %x %X %%",
	'c', "", (void *)-1, 20, -20, -1, -1, 200000000);
	printf("count : %d\n", result);
}
*/
