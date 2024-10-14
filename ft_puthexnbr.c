/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yibrahim <yibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:04 by yibrahim          #+#    #+#             */
/*   Updated: 2024/10/14 17:00:58 by yibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexnbr(size_t arg, int count, char n_type)
{
	if (arg >= 16)
	{
		count = ft_puthexnbr(arg / 16, count, n_type);
	}
	if ((n_type == 'x'))
		count += ft_putchar("0123456789abcdef"[arg % 16]);
	if ((n_type == 'X'))
		count += ft_putchar("0123456789ABCDEF"[arg % 16]);
	return (count);
}