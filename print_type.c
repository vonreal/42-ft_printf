/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:25:31 by jna               #+#    #+#             */
/*   Updated: 2021/01/31 21:25:31 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 반환값은 총 출력한 문자의 갯수이다. */

int		print_character(Field *fields, char c)
{
	int		size;
	int		output;

	size = 1;
	output = size;
	output += apply_option(fields, size);
	write(1, &c, sizeof(char));
	output += apply_option(fields, size);
	return (output);
}

int		print_string(Field *fields, char *s)
{
	int		size;
	int		output;

	if (fields->_precision > 0)
		size = apply_precision(&fields->_precision, ft_strlen(s), fields->_type);
	else
		size = ft_strlen(s);
	output = size;
	output += apply_option(fields, size);
	write(1, s, (sizeof(char) * size));
	output += apply_option(fields, size);
	return (output);
}

int		print_pointer(Field *fields, void *p)
{
	unsigned int	u_num;
	int				size;
	int				output;
	
	u_num = (unsigned int)p;
	size = get_digit_unsigned(u_num, 16) + 2;
	output = size;
	output += apply_option(fields, size);
	write(2, "0x", (sizeof(char) * 2));
	ft_putnbr_unsigned(u_num, 'x');
	output += apply_option(fields, size);
	return (output);
}

int		print_signed_int(Field *fields, int num)
{
	int			size;
	int			output;

	size = get_digit(num);
	if (num == 0 && fields->_precision == 0)
		size = 0;
	output = size;
	setting_option(fields);
	if (num < 0)
	{
		output += 1;
		size += 1;
		if (fields->_flag == ' ')
			output += apply_width(fields, size);
		write(1, "-", sizeof(char));
	}
	if (fields->_flag == '-')
	{
		fields->_flag = ' ';
		output += apply_precision(fields, get_digit(num), fields->_type);
		if (!(num == 0 && fields->_precision == 0))
			ft_putnbr_signed(num);
		output += apply_width(fields, size);
	}
	else if (fields->_flag == '0')
	{
		output += apply_width(fields, size);
		output += apply_precision(fields, get_digit(num), fields->_type);
		if (!(num == 0 && fields->_precision == 0))
			ft_putnbr_signed(num);
	}
	return (output);
}

int		print_unsigned_int(Field *fields, unsigned int u_num, char type)
{
	int			notation;
	int			size;
	int			output;

	notation = (type == 'u') ? 10 : 16;
	size = get_digit_unsigned(u_num, notation);
	output = size;
	output += apply_option(fields, size);
	ft_putnbr_unsigned(u_num, fields->_type);
	output += apply_option(fields, size);
	return (output);
}
