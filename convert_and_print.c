/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:14:22 by jna               #+#    #+#             */
/*   Updated: 2021/02/04 17:14:22 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_character(Field *fields, char c)
{
	int		output;

	output = 1;
	if (fields->_flag != '-')
		output += apply_width(fields, 1);
	write(1, &c, sizeof(char));
	if (fields->_flag == '-')
	{
		fields->_flag = ' ';
		output += apply_width(fields, 1);
	}
	return (output);
}

int		print_string(Field *fields, char *s)
{
	int		size;
	int		output;

	if (s == NULL)
		s = "(null)";
	size = ft_strlen(s);
	if (fields->_precision >= 0)
		size = get_output_size_precision(fields, size);
	output = size;
	if (fields->_flag != '-')
		output += apply_width(fields, size);
	write(1, s, (sizeof(char) * size));
	if (fields->_flag == '-')
	{
		fields->_flag = ' ';
		output += apply_width(fields, size);
	}
	return (output);
}

int		print_pointer(Field *fields, unsigned long u_num)
{
	int				size;
	int				output;

	if (u_num == 0 && fields->_precision == 0)
		size = 2;
	else
		size = get_digit_unsigned(u_num, 16) + 2;
	output = size;
	if (fields->_flag != '-')
		output += apply_width(fields, size);
	write(1, "0x", (sizeof(char) * 2));
	if (!(u_num == 0 && fields->_precision == 0))
		ft_putnbr_unsigned(u_num, 'x');
	if (fields->_flag == '-')
	{
		fields->_flag = ' ';
		output += apply_width(fields, size);
	}
	return (output);
}

int		print_signed_int(Field *fields, int num)
{
	int			size;
	int			minus;
	int			output;

	minus = 0;
	size = get_digit(num);
	if (num == 0 && fields->_precision == 0)
		size = 0;
	output = size;
	if (num < 0)
	{
		minus += 1;
		if (fields->_flag == ' ')
			output += apply_width(fields, size + minus + get_precision(fields, size));
		write(1, "-", sizeof(char));
		output += 1;
	}
	if (fields->_flag != '-')
		output += apply_width(fields, size + minus + get_precision(fields, size));
	output += apply_precision(fields, size);
	if (!(num == 0 && fields->_precision == 0))
		ft_putnbr_signed(num);
	if (fields->_flag == '-')
	{
		fields->_flag = ' ';
		output += apply_width(fields, size + minus + get_precision(fields, size));
	}
	return (output);
}

int		print_unsigned_int(Field *fields, unsigned int u_num, char type)
{
	int			notatiton;
	int			size;
	int			output;

	if (type == 'u')
		notatiton = 10;
	else
		notatiton = 16;
	if (u_num == 0 && fields->_precision == 0)
		size = 0;
	else
		size = get_digit_unsigned(u_num, notatiton);
	output = size;
	if (fields->_flag != '-')
		output += apply_width(fields, size + get_precision(fields, size));
	output += apply_precision(fields, size);
	if (!(u_num == 0 && fields->_precision == 0))
		ft_putnbr_unsigned(u_num, fields->_type);
	if (fields->_flag == '-')
	{
		fields->_flag = ' ';
		output += apply_width(fields, size + get_precision(fields, size));
	}
	return (output);
}
