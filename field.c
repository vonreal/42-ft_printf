/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:16 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 23:18:16 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_width(int value, int length, char c)
{
	int size;

	value -= length;
	if ((size = value) <= 0)
		return (0);
	else
	{
		while (value > 0)
		{
			write(1, &c, sizeof(char));
			value--;
		}
	}
	return (size);
}

int		option(Field *opt, int length)
{
	int         temp;

	if (opt->_type == 's')
	{
		apply_width(opt->_width, length, ' ');
		if (opt->_precision == 0)
			return (0);
		else if (opt->_precision > 0 && opt->_precision <= length)
			return (opt->_precision);
	}
	else
	{
		opt->_flag = (opt->_flag == '0') ? '0' : ' ';
		if ((opt->_precision -= length) > 0)
		{
			opt->_precision += apply_width(opt->_width, opt->_precision, opt->_flag)
			temp = opt->_precision;
			while (temp-- > 0)
				write(1, "0", sizeof(char));
			return (opt->_precision);
		}
	}
	return (length);
}

// int		width(int option, int length, char c)
// {
// 	int		temp;

// 	if ((option -= length) > 0)
// 	{
// 		temp = option;
// 		while (temp-- > 0)
// 		{
// 			if (c == '0')
// 				write(1, "0", sizeof(char));
// 			else
// 				write(1, " ", sizeof(char));
// 		}
// 		return (option);
// 	}
// 	return (0);
// }
