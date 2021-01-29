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
	char	_flag;
	int		_width;
	int		_precision;
	char	_type;
} Field;

void	ft_putnbr_unsigned(unsigned int n, char type)
{
	char			num;
	unsigned int	notation;
	char			hex[17] = "0123456789abcedf";
	char			Hex[17] = "0123456789ABCDEF";

	notation = (type == 'u') ? (notation = 10) : (notation = 16);
	if (n < notation)
	{
		num = n + '0';
		if (type == 'x' || type == 'p')
			write(1, &hex[n], sizeof(char));
		else if (type = 'X')
			write(1, &Hex[n], sizeof(char));
		else
			write(1, &num, 1);
	}
	else
	{
		ft_putnbr_unsigned((n / notation), type);
		ft_putnbr_unsigned((n % notation), type);
	}
}

int		get_digit(unsigned int num, unsigned int notation)
{
	int				digit;

	digit = 1;
	while (num > (notation - 1))
	{
		num /= notation;
		digit++;
	}
	return (digit);
}

void	convert_format_specifier(Field *fields, va_list *ap, int *total)
{
	char			type;
	char			c_temp;
	int				i_temp;
	unsigned int	u_temp;
	void			*v_ptr;
	char			*c_ptr;

	type = fields->_type;
	// if ((fields->flag == '-') && (fields->width > 0))
	// 	fields->width *= -1;

	if (type == 'c')
	{
		c_temp = va_arg(*ap, int);
		write(1, &c_temp, sizeof(char));
		*total += 1;
	}
	else if (type == 's')
	{
		c_ptr = va_arg(*ap, char *);
		write(1, c_ptr, (sizeof(char) * ft_strlen(c_ptr)));
		*total += ft_strlen(c_ptr);
	}
	else if (type == 'p')
	{
		v_ptr = va_arg(*ap, void *);
		u_temp = (unsigned int)v_ptr;
		write(2, "0x", (sizeof(char) * 2));
		ft_putnbr_unsigned(u_temp, type);
		*total += (get_digit(u_temp, 16) + 2);
	}
	else if (type == 'd' || type == 'i')
	{
		i_temp = va_arg(*ap, int);
		ft_putnbr_fd(i_temp, 1);
		//total
	}
	else if (type == 'u' || type == 'x' || type == 'X')
	{
		u_temp = va_arg(*ap, unsigned int);
		if (type == 'u')
		{
			ft_putnbr_unsigned(u_temp, type);
			*total += get_digit(u_temp, 10);
		}
		else
		{
			ft_putnbr_unsigned(u_temp, type)
			*total += get_digit(u_temp, 16);	
		}
	}
	else if (type == '%')
	{
		write(1, "%", sizeof(char));
		*total += 1;
	}
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