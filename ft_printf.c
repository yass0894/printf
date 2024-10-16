/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibrahim <yibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:41:03 by yibrahim          #+#    #+#             */
/*   Updated: 2024/10/16 13:19:51 by yibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printformat(va_list args, const char *specifier)
{
	int	count;

	count = 0;
	if (*specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*specifier == 'd' || *specifier == 'i')
		count += ft_putnbr(va_arg(args, int), 0);
	else if (*specifier == 'u')
		count += ft_putnbr_pos(va_arg(args, unsigned int), 0);
	else if (*specifier == 'x')
		count += ft_puthexnbr(va_arg(args, unsigned int), 0, 'x');
	else if (*specifier == 'X')
		count += ft_puthexnbr(va_arg(args, unsigned int), 0, 'X');
	else if (*specifier == 'p')
		count += ft_pointer(args);
	else if (*specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i +1])
		{
			i++;
			count += ft_printformat(args, &format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*int main(void)
{
    int count;
    //count = ft_printf("Hello %s\n", "Jhon");
    //ft_printf("The chars written are %d\n", count);
    count = ft_printf("%d\n", 0);
    ft_printf("The chars written are %d\n", count);
    count = printf("%x\n", 0);
    printf("The chars written are %d\n", count);
    
}*/
