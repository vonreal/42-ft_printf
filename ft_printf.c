#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

void	set_width(int width)
{
	while (width > 0)
	{
		write (1, " ", sizeof(char));
		width--;
	}
	while (width < 0)
	{
		write(1, " ", sizeof(char));
		width++;
	}
}

int		check_width(const char *format, va_list *ap)
{
	int num;
	int i;

	num = 0;
	i = 0;
	if (format[i] >= '1' && format[i] <= '9')
	{
		while (format[i] >= '1' && format[i] <= '9')
			num = (num * 10) + format[i++] - '0';
	}
	else if (format[i] == '*')
		num = va_arg(*ap, int);
	return (num);
}

int		get_size(int n)
{
	int		count;

	count = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		n *= (-1);
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

//	precision 음수일때는 음수 기호를 제외한 나머지 자릿수로 계산해야함.
//	음수표시는 맨 앞에 해주고
void	precision_number_int(int precision, int num)
{
	precision -= get_size(num);
	while (precision-- > 0)
		write(1, "0", sizeof(char));
}

int		get_size_unum(unsigned int num, unsigned int division_num)
{
	int digit;

	digit = 1;
	while (num > (division_num - 1))
	{
		num /= division_num;
		digit++;
	}
	return (digit);
}

// 10진수일때와 16진수일때의 경우가 다름
void	precision_number(int precision, unsigned int num, unsigned int division_num)
{
	int digit;

	digit = 1;
	while (num > (division_num - 1))
	{
		num /= division_num;
		digit++;
	}
	precision -= digit;
	while (precision-- > 0)
		write(1, "0", sizeof(char));
}

int		check_precision(const char *format, va_list *ap)
{
	int			num;
	int			i;
	char		c;

	i = 0;
	num = 0;
	c = '0';
	if (format[i] == '*')
	{
		num = va_arg(*ap, int);
		c = format[i + 1];
	}
	else if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
			num = (num * 10) + format[i++] - '0';
		c = format[i];
	}
	if (format[i] == 's')
		return (num);
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x'|| c == 'X' || c == 's')
		return (num);
	return (-1);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	char			num;

	if (n < 10)
	{
		num = n + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
}

void	ft_putnbr(int n)
{
	char			num;

	if (n == -2147483648)
		write(1, "2147483648", 10);
	else if (n < 0)
		ft_putnbr(n * (-1));
	else if (n < 10)
	{
		num = n + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	get_hex_and_print(unsigned int n, char *hex)
{
	if (n < 16)
		write(1, &hex[n], sizeof(char));
	else
	{
		get_hex_and_print((n / 16), hex);
		get_hex_and_print((n % 16), hex);
	}
}

// [Comment] conversion에 따라 출력하는 함수
void	print_conversion(char conversion, va_list *ap, int width, int precision)
{
	char			c;
	char			*str;
	char			hex[17] = "0123456789abcdef";
	char			HEX[17] = "0123456789ABCDEF";
	int				num;
	unsigned int 	u_num;
	void			*v_ptr;

	if (conversion == 'c')
	{
		c = va_arg(*ap, int);
		if (width > 0)
			set_width(width - 1);
		write(1, &c, sizeof(char));
		if (width < 0)
			set_width(width + 1);
	}
	else if (conversion == 's')
	{
		// [Improving] Use the malloc and free function.
		str = va_arg(*ap, char *);
		num = 0;
		while (str[num])
			num++;
		// precision가 문자열보다 더 큰 경우는 그대로 출력임
		if (precision >= 0 && precision <= num)
			num = precision;
		if (width > 0)
		{
			if ((width -= num) > 0)
				set_width(width);
			width = 1;
		}
		write(1, str, (sizeof(char) * num));
		if (width < 0)
		{
			if ((width += num) < 0)
				set_width(width);
		}
	}
	else if (conversion == 'p')
	{
		v_ptr = va_arg(*ap, void *);
		u_num = (unsigned int)v_ptr;
		if (width > 0)
		{
			if ((width -= (get_size_unum(u_num, 16) + 2)) > 0)
				set_width(width);
			width = 1;
		}
		write(2, "0x", (sizeof(char) * 2));
		get_hex_and_print(u_num, hex);
		if (width < 0)
		{
			if ((width += (get_size_unum(u_num, 16) + 2)) < 0)
				set_width(width);
		}
	}
	else if (conversion == 'd' || conversion == 'i')
	{
		num = va_arg(*ap, int);
		if (num < 0)
		{
			write(1, "-", sizeof(char));
			precision += 1;
		}
		if (width > 0)
		{
			if (precision >= 0)
				width -= (get_size(num) + (precision - get_size(num)));
			else
				width -= get_size(num);
			if (width > 0)
				set_width(width);
			width = 1;
		}
		if (precision >= 0)
			precision_number_int(precision, num);
		ft_putnbr(num);
		if (width < 0)
		{
			if (precision >= 0)
				width += (get_size(num) + (precision - get_size(num)));
			else
				width += get_size(num);
			if (width < 0)
				set_width(width);
		}
	}
	else if (conversion == 'u')
	{
		u_num = va_arg(*ap, unsigned int);
		if (width > 0)
		{
			if (precision >= 0)
				width -= (get_size_unum(u_num, 10) + (precision - get_size_unum(u_num, 10)));
			else
				width -= get_size_unum(u_num, 10);
			if (width > 0)
				set_width(width);
			width = 1;
		}
		if (precision >= 0)
			precision_number(precision, u_num, 10);
		ft_putnbr_unsigned(u_num);
		if (width < 0)
		{
			if (precision >= 0)
				width += (get_size_unum(u_num, 10) + (precision - get_size_unum(u_num, 10)));
			else
				width += get_size_unum(u_num, 10);
			if (width < 0)
				set_width(width);
		}
	}
	else if (conversion == 'x' || conversion == 'X')
	{
		u_num = va_arg(*ap, unsigned int);
		if (width > 0)
		{
			if (precision >= 0)
				width -= (get_size_unum(u_num, 16) + (precision - get_size_unum(u_num, 16)));
			else
				width -= get_size_unum(u_num, 16);
			if (width > 0)
				set_width(width);
			width = 1;
		}
		if (precision >= 0)
			precision_number(precision, u_num, 16);
		(conversion == 'x') ? get_hex_and_print(u_num, hex) : get_hex_and_print(u_num, HEX);
		if (width < 0)
		{
			if (precision >= 0)
				width += (get_size_unum(u_num, 16) + (precision - get_size_unum(u_num, 16)));
			else
				width += get_size_unum(u_num, 16);
			if (width < 0)
				set_width(width);
		}
	}
	else if (conversion == '%')
	{
		if (width > 0)
			set_width(width - 1);
		write(1, "%", sizeof(char));
		if (width < 0)
			set_width(width + 1);
	}
}

// [Comment] %를 만나면 conversion까지 읽어와 해당 조건에 맞게 출력하는 함수
int		replace_and_print(const char *format, int i, va_list *ap)
{
	int				j;
	char			*conversion;
	int				width;
	int				precision;

	// [Improving] Change to static varialbe and use ft_strlcpy funcion.
	width = 0;
	precision = -1;
	conversion = "cspdiuxX%";
	while (format[i])
	{
		if (width == 0)
		{
			if ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
				width = check_width(&format[i], ap);
		}
		if (format[i] == '.')
			precision = check_precision(&format[i + 1], ap);
		j = 0;
		while (conversion[j])
		{
			if (format[i] == conversion[j])
				break ;
			j++;
		}
		if (format[i] == conversion[j])
			break ;
		i++;
	}
	print_conversion(conversion[j], ap, width, precision);
	if (format[i] == '\0')
		return (-1);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int				idx;
	va_list			ap;

	idx = 0;
	va_start(ap, format);
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			idx = replace_and_print(format, ++idx, &ap);
			if (idx == -1)
				return (-1);
		}
		else
			write(1, &format[idx], sizeof(char));
		idx++;
	}
	va_end(ap);
	return (0);
}
