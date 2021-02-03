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

void	convert_format_specifier(Field *fields, va_list *ap, int *total)
{
	char	c;
	char	type;

	type = fields->_type;
	if (type == 'c' || type == '%')
	{
		if (type == '%')
			c = '%';
		else
			c = va_arg(*ap, int);
		*total += print_character(fields, c);
	}
	else if (type == 's')
		*total += print_string(fields, va_arg(*ap, char *));
	else if (type == 'p')
		*total += print_pointer(fields, va_arg(*ap, void *));
	else if (type == 'd' || type == 'i')
		*total += print_signed_int(fields, va_arg(*ap, int));
	else if (type == 'u' || type == 'x' || type == 'X')
		*total += print_unsigned_int(fields, va_arg(*ap, unsigned int), type);
}

int		scan_syntax(const char *format, int idx, va_list *ap, int *total)
{
	Field	fields;

	while (format[idx])
	{
		idx += find_flag_and_set(&format[idx], &fields._flag);
		idx += find_width_and_set(&format[idx], &fields._width, ap);
		idx += find_precision_and_set(&format[idx], &fields._precision, ap);
		idx += find_type_and_set(&format[idx], &fields._type);
		if (format[idx] == fields._type)
			break ;
		idx++;
	}
	if (format[idx] == '\0')
		return (-1);
	else
		convert_format_specifier(&fields, ap, total);
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
			if ((idx = scan_syntax(format, idx + 1, &ap, &total)) == -1)
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
