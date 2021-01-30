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
		if (opt->_flag != '-')
			apply_width(opt->_width, length, ' ');
		if (opt->_precision == 0)
			return (0);
		else if (opt->_precision > 0 && opt->_precision <= length)
			return (opt->_precision);
	}
	else
	{
		temp = opt->_precision - length;
		if (temp > 0)
		{
			opt->_precision = temp;
			if (opt->_flag != '-')
				opt->_precision += apply_width(opt->_width, temp + length, opt->_flag);
			temp = opt->_precision;
			while (temp-- > 0)
				write(1, "0", sizeof(char));
			return (opt->_precision + length);
		}
		else
		{
			if (opt->_flag != '-')
				length += apply_width(opt->_width, length, opt->_flag);
		}
	}
	return (length);
}
