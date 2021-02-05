/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:56:03 by jna               #+#    #+#             */
/*   Updated: 2021/02/05 14:22:45 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setting_option(t_field *opt)
{
	if (opt->_flag != ' ')
	{
		if (opt->_width == 0)
			opt->_flag = ' ';
		else
		{
			if (opt->_flag == '0')
			{
				if (opt->_precision >= 0 && opt->_type != '%')
					opt->_flag = ' ';
				if (opt->_type == 'c' || opt->_type == 's' || opt->_type == 'p')
					opt->_flag = ' ';
			}
		}
	}
	if (opt->_width != 0)
	{
		if (opt->_width < 0)
		{
			(opt->_flag) = '-';
			(opt->_width) *= -1;
		}
	}
}

int		get_output_size_precision(t_field *opt, int length)
{
	int		output;

	if (opt->_precision > 0)
	{
		if (opt->_type == 's')
		{
			if (opt->_precision <= length)
				output = opt->_precision;
			else
				output = length;
		}
		else
		{
			if ((opt->_precision - length) > 0)
				output = opt->_precision - length;
			else
				output = 0;
		}
	}
	else
		output = 0;
	return (output);
}

int		get_output_size_width(int *width, int length)
{
	int		output;

	if (*width > 0)
	{
		if ((*width - length) > 0)
			output = *width - length;
		else
			output = 0;
	}
	else
		output = 0;
	return (output);
}

int		apply_precision(t_field *opt, int length)
{
	int		temp;

	if (length == 0)
		return (0);
	length = get_output_size_precision(opt, length);
	if (length > 0)
	{
		temp = length;
		while (temp-- > 0)
			write(1, "0", sizeof(char));
	}
	else
	{
		length = 0;
	}
	return (length);
}

int		apply_width(t_field *opt, int length)
{
	int		temp;

	length = get_output_size_width(&opt->_width, length);
	if (length > 0)
	{
		temp = length;
		while (temp-- > 0)
			write(1, &opt->_flag, sizeof(char));
	}
	else
	{
		length = 0;
	}
	opt->_width = 0;
	return (length);
}