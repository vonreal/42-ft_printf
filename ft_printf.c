/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:27:43 by jna               #+#    #+#             */
/*   Updated: 2021/01/29 17:27:43 by jna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct _Field
{
	char	flag;
	int		width;
	int		precision;
	char	type;
} Field;


int		convert_format_specifier(Field *fields, va_list *ap)
{
	if ((*fields->flag == '-') && (*fields->width > 0))
		*fields->width *= -1;

	return (0);
}

int		set_width(int *dst, const char *format, int idx, va_list *ap)
{
	int num;

	num = 0;
	if (format[idx++] == '*')
		num = va_arg(*ap, int);
	else
	{
		while (format[idx] >= '0' && format[idx] <= '9')
			num = (num * 10) + format[idx++] - '0';	
	}
	*dst = num;
	return (idx);
}

int		scan_syntax(const char *format, int idx, va_list *ap, int total)
{
	Field	fields;
	char	type[11] = "cspdiuxX%";
	int		count;

	ft_memset(&fields, 0, sizeof(Field));
	while (format[idx])
	{
		while (format[idx] == '-' || format[idx] == '0')
		{
			if (fields.flag == '-')
				continue ;
			fields.flag = format[idx];
		}
		if ((format[idx] >= '1' && format[idx] <= '9') || format[idx] == '*')
			idx = set_width(&fields.width, format, idx, ap);
		if (format[idx] == '.')
			idx = set_width(&fields.precision, format, idx, ap);
		count = 0;
		while (type[count])
		{
			if (format[idx] == type[count])
				fields.type = format[idx];
			count++;
		}
		if (format[idx] == fields.type)
			break ;
		idx++;
	}
	convert_format_specifier(&fields, ap);
	if (format[idx] == '\0')
		return (-1);
	return (idx);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		idx;
	int		total;

	idx = 0;
	total = 0;
	va_start(ap, format);
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			if ((idx = scan_syntax(format, idx + 1, &ap, total)) == -1)
				return (-1);
		}
		else
		{
			write(1, &format[idx], sizeof(char));
			total++;
		}
		idx++;
	}
	va_end(ap);
	return (total);
}