/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:27:18 by jna               #+#    #+#             */
/*   Updated: 2021/01/31 20:27:18 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_flag_and_set(const char *format, char *flag)
{
	int		idx;

	idx = 0;
	*flag = ' ';
	while (format[idx] == '-' || format[idx] == '0')
	{
		if (*flag == '-')
		{
			idx++;
			continue ;
		}
		*flag = format[idx];
		idx++;
	}
	return (idx);
}

int		set_num(int *dst, const char *format, va_list *ap)
{
	int num;
	int	idx;

	num = 0;
	idx = 0;
	if (format[idx] == '*')
	{
		num = va_arg(*ap, int);
		idx++;
	}
	else
	{
		while (format[idx] >= '0' && format[idx] <= '9')
			num = (num * 10) + format[idx++] - '0';	
	}
	*dst = num;
	return (idx);
}

int		find_width_and_set(const char *format, int *width, va_list *ap)
{
	int		idx;
	
	idx = 0;
	*width = 0;
	if ((format[idx] >= '1' && format[idx] <= '9') || format[idx] == '*')
		idx += set_num(width, &format[idx], ap);
	return (idx);
}

int		find_precision_and_set(const char *format, int *precision, va_list *ap)
{
	int		idx;

	idx = 0;
	*precision = -1;
	if (format[idx] == '.')
	{
		idx++;
		if ((format[idx] >= '0' && format[idx] <= '9') || format[idx] == '*')
			idx += set_num(precision, &format[idx], ap);
		else if (format[idx] == 's')
			*precision = 0;
		else
			*precision = -1;
	}
	return (idx);
}

int		find_type_and_set(const char *format, char *type)
{
	char	types[11] = "cspdiuxX%";
	int		idx;
	int		jdx;

	idx = 0;
	jdx = 0;
	while (format[idx])
	{
		while (types[jdx])
		{
			if (format[idx] == types[jdx])
			{
				*type = format[idx];
				break ;
			}
			jdx++;
		}
		idx++;
	}
	return (idx);
}