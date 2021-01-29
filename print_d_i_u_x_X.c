/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i_u_x_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:56:04 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 22:56:04 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_signed(int n)
{
	char			num;

	if (n == -2147483648)
		write(1, "2147483648", 10);
	else if (n < 0)
		ft_putnbr_signed(n * (-1));
	else if (n < 10)
	{
		num = n + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr_signed(n / 10);
		ft_putnbr_signed(n % 10);
	}
}

void	ft_putnbr_unsigned(unsigned int n, char type)
{
	char			num;
	unsigned int	notation;
	char			hex[17] = "0123456789abcdef";
	char			Hex[17] = "0123456789ABCDEF";

	notation = (type == 'u') ? (notation = 10) : (notation = 16);
	if (n < notation)
	{
		num = n + '0';
		if (type == 'x' || type == 'p')
			write(1, &hex[n], sizeof(char));
		else if (type = 'X')
			write(1, &Hex[n], sizeof(char));
		else
			write(1, &num, 1);
	}
	else
	{
		ft_putnbr_unsigned((n / notation), type);
		ft_putnbr_unsigned((n % notation), type);
	}
}

int		print_signed_int(int num, int value)
{
	int				size;

	size = get_digit(num);
	if (num < 0)
	{
		write(1, "-", sizeof(char));
		value += 1;
	}
	size = precision(value, size, '0');
	ft_putnbr_signed(num);
	return (size);
}

int		print_unsigned_int(unsigned int num, char type, int value)
{
	int				size;

	if (type == 'u')
	{
		size = get_digit_unsigned(num, 10);
		size = precision(value, size, '0');
		ft_putnbr_unsigned(num, type);
	}
	else if (type == 'x' || type == 'X' || type == 'p')
	{
		size = get_digit_unsigned(num, 16);
		size = precision(value, size, '0');
		ft_putnbr_unsigned(num, type);
	}
	return (size);
}
