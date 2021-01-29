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
	char			type;
	int				i_temp;
	char			c_temp;
	void			*v_ptr;
	char			*c_ptr;

	if (type == 'c' || type == '%')
	{
		if (type == '%')
		{
			write(1, "%", sizeof(char));
		}
		else
		{
			c_temp = va_arg(*ap, int);
			write(1, &c_temp, sizeof(char));
		}
		*total += 1;
	}
	else if (type == 's')
	{
		c_ptr = va_arg(*ap, char *);
		i_temp = precision(fields->_precision, ft_strlen(c_ptr), type);
		write(1, c_ptr, (sizeof(char) * i_temp));
		*total += i_temp;
	}
	else if (type == 'p')
	{
		v_ptr = va_arg(*ap, void *);
		write(2, "0x", (sizeof(char) * 2));
		*total += (print_unsigned_int((unsigned int)v_ptr, type, -1));
	}
	else if (type == 'd' || type == 'i')
		*total += print_signed_int(va_arg(*ap, int), fields->_precision);
	else if (type == 'u' || type == 'x' || type == 'X')
		*total += print_unsigned_int(va_arg(*ap, unsigned int), type, fields->_precision);
}

int		set_width(int *dst, const char *format, int idx, va_list *ap)
{
	int num;

	num = 0;
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

int		scan_syntax(const char *format, int idx, va_list *ap, int *total)
{
	Field	fields;
	char	type[11] = "cspdiuxX%";
	int		count;

	ft_memset(&fields, 0, sizeof(Field));
	fields._precision = -1;
	while (format[idx])
	{
		while (format[idx] == '-' || format[idx] == '0')
		{
			if (fields._flag == '-')
			{
				idx++;
				continue ;
			}
			fields._flag = format[idx];
			idx++;
		}
		if ((format[idx] >= '1' && format[idx] <= '9') || format[idx] == '*')
			idx = set_width(&fields._width, format, idx, ap);
		if (format[idx] == '.')
			idx = set_width(&fields._precision, format, ++idx, ap);
		count = 0;
		while (type[count])
		{
			if (format[idx] == type[count])
				fields._type = format[idx];
			count++;
		}
		if (format[idx] == fields._type)
			break ;
		idx++;
	}
	convert_format_specifier(&fields, ap, total);
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