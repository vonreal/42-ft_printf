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
	return (0);
}

void	field_rules(Field *fields)
{
	if ((*fields->flag == '-') && (*fields->width > 0))
		*fields->width *= -1;
}

int		scan_syntax(const char *format, int idx, va_list *ap, int total)
{
	char	fmt;
	Field	fields;

	ft_memset(&fields, 0, sizeof(Field));
	while (format[idx])
	{
		fmt = format[idx];
		if (fmt == '-' || fmt == '0')
		if ((fmt >= '1' && fmt <= '9') || fmt == '*')
		if (fmt == '.')
		if (fmt == 'c' || fmt == 's' || fmt == 'p'
					   || fmt == 'd' || fmt == 'i'
					   || fmt == 'u' || fmt == 'x'
					   || fmt == 'X' || fmt == '%')
		{
			fields.type = fmt;
			break ;
		}
		idx++;
	}
	field_rules(&fields);
	convert_format_specifier(&fields, ap);
	if (format[idx] == '\0')
		return (-1);
	return (idx);
}

int		ft_printf(const char *format, ...)
{
	int		idx;
	int		total;
	va_list	ap;

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