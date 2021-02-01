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

int		print_character(Field fields, char c)
{
	int		length;

	length = 1;
	length += apply_option(fields, length);
	write(1, &c, sizeof(char));
	length += apply_option(fields, length);
	return (length);
}

int		print_string(Field fields, char *s)
{
	int		length;
	int		size;

	length = 0;
	size = apply_precision(fields->_precision, ft_strlen(s));
	length = apply_option(fields, size) + size;
	write(1, s, (sizeof(char) * size));
	length += apply_option(fields, length);
	return (length);
}

// '%p' == '%#x' ('#' means append '0x')
int		print_pointer(Field fields, void *p)
{
	unsigned int	u_num;
	int				length;
	int				size;

	u_num = (unsigned int)*p;
	size = get_digit_unsigned(u_num, 16) + 2;
	length = apply_option(fields, size);
	write(2, "0x", (sizeof(char) * 2));
	ft_putnbr_unsigned(u_num, 'x');
	length += apply_option(fields, size);
	return (length);
}

int		print_signed_int(Field fields, int num)
{
	int			length;
	int			size;

	length = 0;
	size = get_digit(num);
	if (num < 0)
	{
		fields->_precision += 1;
		length += apply_width(fields, size);
		write(1, "-", sizeof(char));
	}
	// TODO: num이 음수면 -를 제외한 자릿수에 옵션을 적용해야 한다.
	//		 이 부분은 일단 나중에 처리한다.
	length += apply_precision(fields->_precision, size);
	ft_putnbr_signed(num);
	length += apply_width(fields, size);
	return (length);
}

int		print_unsigned_int(Field fields, unsigned int u_num, char type)
{
	int			length;
	int			size;
	int			notation;

	notation = (type == 'u') ? 10 : 16;
	size = get_digit_unsigned(u_num, notation);
	length = apply_option(fields, size);
	ft_putnbr_unsigned(u_num, fields->_type);
	length += apply_option(fields, size);
	return (length);
}