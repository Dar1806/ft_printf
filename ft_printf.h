/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:17:14 by nmeunier          #+#    #+#             */
/*   Updated: 2025/11/24 11:23:06 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar(const char c, int count);
int		ft_putstr(const char *str, int count);
int		ft_voidhexa(void *adress, int count);
int		ft_putnbr(int nbr, int count);
int		ft_unsigned_nbr(unsigned int nbr, int count);
int		check(const char *str, int i, va_list *args);
int		ft_putnbrhexa_low(long unsigned n, int count);
int		ft_putnbrhexa_up(long unsigned n, int count);

#endif
