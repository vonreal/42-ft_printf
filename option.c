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
	if (opt->s_flag != ' ')
	{
		if (opt->s_width == 0)
			opt->s_flag = ' ';
		else
		{
			if (opt->s_flag == '0')
			{
				if (opt->s_precision >= 0 && opt->s_type != '%')
					opt->s_flag = ' ';
				if (opt->s_type == 'c' || opt->s_type == 's'
										|| opt->s_type == 'p')
					opt->s_flag = ' ';
			}
		}
	}
	if (opt->s_width != 0)
	{
		if (opt->s_width < 0)
		{
			(opt->s_flag) = '-';
			(opt->s_width) *= -1;
		}
	}
}

int		get_output_size_precision(t_field *opt, int length)
{
	int		output;

	if (opt->s_precision > 0)
	{
		if (opt->s_type == 's')
		{
			if (opt->s_precision <= length)
				output = opt->s_precision;
			else
				output = length;
		}
		else
		{
			if ((opt->s_precision - length) > 0)
				output = opt->s_precision - length;
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

	length = get_output_size_width(&opt->s_width, length);
	if (length > 0)
	{
		temp = length;
		while (temp-- > 0)
			write(1, &opt->s_flag, sizeof(char));
	}
	else
	{
		length = 0;
	}
	opt->s_width = 0;
	return (length);
}
