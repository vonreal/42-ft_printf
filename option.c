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
	if (opt->_flag == '0' && (opt->_type == 'c' || opt->_type == 'p'))
	{
		opt->_flag = ' ';
		opt->_precision = -1;
	}
	if (opt->_flag == '0' && (opt->_width == 0 || opt->_type == 's'))
		opt->_flag = ' ';
	if (opt->_precision < 0 || opt->_type == '%')
		opt->_precision = -1;
}

int		apply_width(Field *opt, int length)
{
	int		temp;
	char	flag;

	if (opt->_width == 0)
		return (0);
	else
	{
		if (opt->_precision != -1)
		{
			if (opt->_type == 's')
				length = apply_precision(&opt->_precision, length, opt->_type);
			else
				length = (opt->_precision) - length;
		}
		if (length > 0)
			length = (opt->_width) - length;
		if (length < 0)
			length = 0;
		else
		{
			temp = length;
			while (temp-- > 0)
			{
				flag = opt->_flag;
				write(1, &flag, sizeof(char));
			}
		}
	}
	opt->_width = 0;
	return (length);
}

int		apply_precision(int *precision, int length, char type)
{
	int		temp;

	if (*precision < 0)
		return (0);
	else
	{
		if (type == 's' && *precision <= length)
			return (*precision);
		else if (type == 's' && *precision > length)
			return (length);
		else
		{
			length = *precision - length;
			if (length < 0)
				length = 0;
			else
			{
				temp = length;
				while (temp-- > 0)
					write(1, "0", sizeof(char));
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
	if (opt->_flag == '-')
	{
		opt->_flag = ' ';
		print_size += apply_precision(&opt->_precision, length, opt->_type);
	}
	else
	{
		print_size += apply_width(opt, length);
		print_size += apply_precision(&opt->_precision, length, opt->_type);
	}
	return (print_size);
}
