/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:44:02 by jna               #+#    #+#             */
/*   Updated: 2021/02/05 13:44:02 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_digit(int n)
{
	int				digit;

	digit = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (10);
		n *= (-1);
	}
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int		get_digit_unsigned(unsigned long num, unsigned int notation)
{
	int				digit;

	digit = 1;
	while (num > (notation - 1))
	{
		num /= notation;
		digit++;
	}
	return (digit);
}
