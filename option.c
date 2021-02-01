/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:59:17 by jna               #+#    #+#             */
/*   Updated: 2021/01/31 20:59:17 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setting_option(Field *opt)
{
	if (opt->_width < 0)
	{
		(opt->_flag) = '-';
		(opt->_width) *= -1;
	}
	if (opt->_type == 'c' || opt->_type == 'p')
	{
		opt->_flag = ' ';
		opt->_precision = -1;
	}
	if (opt->_width == 0 || opt->_type == 's')
		opt->_flag = ' ';
	if (opt->_precision < 0 ||opt->_type == '%')
		opt->_precision = -1
}

int		apply_width(Field *opt, int length)
{
	int		temp;

	if (opt->_width == 0)
		return (0);
	else
	{
		length -= (opt->_width);
		if (opt->_precision != -1)
			length -= (opt->_precision);
		if (length < 0)
			return (0);
		else
		{
			temp = length;
			while (temp-- > 0)
				write(1, opt->_flag, sizeof(char));
		}
	}
	opt->_width = 0;
	return (length)
}

int		apply_precision(int *precision, int length)
{
	int		temp;

	if (*precision < 0)
		return (0);
	else
	{
		if (opt->_type == 's' && *precision <= length)
			return (*precision);
		else
		{
			length -= *precision;
			if (length < 0)
				return (0);
			else
			{
				temp = length;
				while (temp-- > 0)
					write(1, " ", sizeof(char));
			}
		}
	}
	*precision = -1;
	return (length);
}

int		apply_option(Field *opt, int length)
{
	int		print_size;

	print_size = 0;
	setting_option(opt);
	if (opt->_flag != '-')
	{
		print_size += apply_width(opt, length);
		print_size += apply_precision(opt->_precision, length);
	}
	else
		print_size += apply_width(opt, length);
	return (print_size);
}
