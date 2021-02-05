/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:43:39 by jna               #+#    #+#             */
/*   Updated: 2021/02/05 14:36:35 by jna              ###   ########.fr       */
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

void	ft_putnbr_unsigned(unsigned long n, char type)
{
	char			num;
	unsigned int	notation;
	char			*small_hex;
	char			*upper_hex;

	small_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	notation = 16;
	if (type == 'u')
		notation = 10;
	if (n < notation)
	{
		num = n + '0';
		if (type == 'x' || type == 'p')
			write(1, &small_hex[n], sizeof(char));
		else if (type == 'X')
			write(1, &upper_hex[n], sizeof(char));
		else
			write(1, &num, 1);
	}
	else
	{
		ft_putnbr_unsigned((n / notation), type);
		ft_putnbr_unsigned((n % notation), type);
	}
}

int		num_is_minus(t_field *fields, int *minus, int size)
{
	int		size_pre;
	int		output;

	minus += 1;
	output = 0;
	size_pre = get_output_size_precision(fields, size);
	if (fields->s_flag == ' ')
			output += apply_width(fields, size + minus + size_pre);
	write(1, "-", sizeof(char));
	output += 1;
	return (output);
}