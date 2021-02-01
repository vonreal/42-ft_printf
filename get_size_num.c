/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_d_i_u_x_X.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:41:22 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 22:41:22 by jna              ###   ########.fr       */
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
			return (11);
		n *= (-1);
		digit++;
	}
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int		get_digit_unsigned(unsigned int num, unsigned int notation)
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
