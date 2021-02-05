/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:27:18 by jna               #+#    #+#             */
/*   Updated: 2021/02/05 14:14:39 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_flag_and_set(const char *fmt, char *flag)
{
	int		idx;

	idx = 0;
	*flag = ' ';
	if (fmt[idx] == '-' || fmt[idx] == '0')
	{
		while (fmt[idx] == '-' || fmt[idx] == '0')
		{
			if (*flag == '-')
			{
				idx++;
				continue ;
			}
			*flag = fmt[idx];
			idx++;
		}
	}
	return (idx);
}

int		set_num(int *dst, const char *fmt, va_list *ap)
{
	int num;
	int	idx;

	num = 0;
	idx = 0;
	if (fmt[idx] == '*')
	{
		num = va_arg(*ap, int);
		idx++;
	}
	else
	{
		while (fmt[idx] >= '0' && fmt[idx] <= '9')
			num = (num * 10) + fmt[idx++] - '0';
	}
	*dst = num;
	return (idx);
}

int		find_width_and_set(const char *fmt, int *width, va_list *ap)
{
	int		idx;

	idx = 0;
	*width = 0;
	if ((fmt[idx] >= '1' && fmt[idx] <= '9') || fmt[idx] == '*')
		idx += set_num(width, &fmt[idx], ap);
	return (idx);
}

int		find_precision_and_set(const char *fmt, int *precision, va_list *ap)
{
	int		idx;

	idx = 0;
	*precision = -1;
	if (fmt[idx] == '.')
	{
		idx++;
		if ((fmt[idx] >= '0' && fmt[idx] <= '9') || fmt[idx] == '*')
			idx += set_num(precision, &fmt[idx], ap);
		else if (fmt[idx] == 'c' || fmt[idx] == '%')
			*precision = -1;
		else
			*precision = 0;
	}
	return (idx);
}

int		find_type_and_set(const char *fmt, char *type)
{
	char	*types;
	int		idx;
	int		jdx;

	idx = 0;
	jdx = 0;
	types = "cspdiuxX%";
	while (fmt[idx])
	{
		while (types[jdx])
		{
			if (fmt[idx] == types[jdx])
			{
				*type = fmt[idx];
				break ;
			}
			jdx++;
		}
		if (fmt[idx] == *type)
			break ;
		idx++;
	}
	return (idx);
}
