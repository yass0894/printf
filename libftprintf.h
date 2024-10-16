/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibrahim <yibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:29:41 by yibrahim          #+#    #+#             */
/*   Updated: 2024/10/16 14:01:13 by yibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb, int count);
int	ft_putnbr_pos(unsigned int n, int count);
int	ft_puthexnbr(size_t arg, int count, char n_type);
int	ft_pointer(va_list args);
int	ft_printformat(va_list args, const char *specifier);
int	ft_printf(const char *format, ...);

#endif
