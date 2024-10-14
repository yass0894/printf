/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibrahim <yibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:48:01 by yibrahim          #+#    #+#             */
/*   Updated: 2024/10/14 16:59:25 by yibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putstr(char *str)
{
	int	count;
	
	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int nb, int count)
{
	if (nb == 0)
			return (ft_putchar('0'));
	if (nb == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putstr("2147483648");
		return (count);
	}
	else if (nb < 0)
	{
		count = ft_putchar('-');
		count = ft_putnbr(-nb, count);
	}
	if (nb > 9)
	{
		count = ft_putnbr(nb / 10, count);
		count += ft_putchar((nb % 10) + '0');
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
int	ft_putnbr_pos(unsigned int nb, int count)
{
	if (nb == 0)
			return (ft_putchar('0'));
	if (nb > 9)
	{
		count = ft_putnbr_pos(nb / 10, count);
		count += ft_putchar ((nb % 10) + '0');
	}
	else
			count += ft_putchar(nb + '0');
	return (count);
}
int	ft_pointer(va_list args)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += puthexnbr((size_t)ptr, 0, 'x');
	}
	return (count);
}

/* putnbr 
putnbr_pos
puthexdec */