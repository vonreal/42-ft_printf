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

int		print_character(t_field *fields, char c)
{
	int		output;

	output = 1;
	if (fields->s_flag != '-')
		output += apply_width(fields, 1);
	write(1, &c, sizeof(char));
	if (fields->s_flag == '-')
	{
		fields->s_flag = ' ';
		output += apply_width(fields, 1);
	}
	return (output);
}

int		print_string(t_field *fields, char *s)
{
	int		size;
	int		output;

	if (s == NULL)
		s = "(null)";
	size = ft_strlen(s);
	if (fields->s_precision >= 0)
		size = get_output_size_precision(fields, size);
	output = size;
	if (fields->s_flag != '-')
		output += apply_width(fields, size);
	write(1, s, (sizeof(char) * size));
	if (fields->s_flag == '-')
	{
		fields->s_flag = ' ';
		output += apply_width(fields, size);
	}
	return (output);
}

int		print_pointer(t_field *fields, unsigned long u_num)
{
	int				size;
	int				output;

	if (u_num == 0 && fields->s_precision == 0)
		size = 2;
	else
		size = get_digit_unsigned(u_num, 16) + 2;
	output = size;
	if (fields->s_flag != '-')
		output += apply_width(fields, size);
	write(1, "0x", (sizeof(char) * 2));
	if (!(u_num == 0 && fields->s_precision == 0))
		ft_putnbr_unsigned(u_num, 'x');
	if (fields->s_flag == '-')
	{
		fields->s_flag = ' ';
		output += apply_width(fields, size);
	}
	return (output);
}

int		print_signed_int(t_field *fields, int num)
{
	int			size;
	int			minus;
	int			output;
	int			size_pre;

	minus = 0;
	size = get_digit(num);
	if (num == 0 && fields->s_precision == 0)
		size = 0;
	output = size;
	size_pre = get_output_size_precision(fields, size);
	if (num < 0)
		output += num_is_minus(fields, &minus, size);
	if (fields->s_flag != '-')
		output += apply_width(fields, size + minus + size_pre);
	output += apply_precision(fields, size);
	if (!(num == 0 && fields->s_precision == 0))
		ft_putnbr_signed(num);
	if (fields->s_flag == '-')
	{
		fields->s_flag = ' ';
		output += apply_width(fields, size + minus + size_pre));
	}
	return (output);
}

int		print_unsigned_int(t_field *fields, unsigned int u_num)
{
	int			notatiton;
	int			size;
	int			output;

	if (fields->s_type == 'u')
		notatiton = 10;
	else
		notatiton = 16;
	if (u_num == 0 && fields->s_precision == 0)
		size = 0;
	else
		size = get_digit_unsigned(u_num, notatiton);
	output = size;
	if (fields->s_flag != '-')
		output += apply_width(fields, size + get_output_size_precision(fields, size));
	output += apply_precision(fields, size);
	if (!(u_num == 0 && fields->s_precision == 0))
		ft_putnbr_unsigned(u_num, fields->s_type);
	if (fields->s_flag == '-')
	{
		fields->s_flag = ' ';
		output += apply_width(fields, size + get_output_size_precision(fields, size));
	}
	return (output);
}
