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
		count += ft_putchar(va_arg(*args, int), count);
	else if (str[i] == 's')
		count += ft_putstr(va_arg(*args, char *), count);
	else if (str[i] == 'p')
		count += ft_voidhexa(va_arg(*args, void *), count);
	else if (str[i] == 'x')
		count += ft_putnbrhexa_low(va_arg(*args, int), count);
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
			i++;
			continue ;
		}
		write(1, &str[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	result;

	result = 0;
	result = ft_printf("test de c : %c test de s : %s\n", 'o', "oui");
	printf("count : %d\n", result);
}
