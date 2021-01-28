#include <stdarg.h>
#include <unistd.h>

int		check_precision(const char *format, va_list *ap)
{
	int			num;
	int			i;
	char		c;

	i = 0;
	num = 0;
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
	if (num >= 0)
	{
		if (c == 'd' || c == 'i' || c == 'u' || c == 'x'|| c == 'X' || c == 's')
			return (num);
	}
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
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * (-1));
	}
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
void	print_conversion(char conversion, va_list *ap, int precision)
{
	char			c;
	char			*str;
	char			hex[17] = "0123456789abcdef";
	char			HEX[17] = "0123456789ABCDEF";
	int				num;
	int				temp;
	unsigned int 	u_num;
	void			*v_ptr;

	if (conversion == 'c')
	{
		c = va_arg(*ap, int);
		write(1, &c, sizeof(char));
	}
	else if (conversion == 's')
	{
		// [Improving] Use the malloc and free function.
		str = va_arg(*ap, char *);
		num = 0;
		while (str[num])
			num++;
		write(1, str, (sizeof(char) * num));
	}
	else if (conversion == 'p')
	{
		v_ptr = va_arg(*ap, void *);
		u_num = (unsigned int)v_ptr;
		write(2, "0x", (sizeof(char) * 2));
		get_hex_and_print(u_num, hex);
	}
	else if (conversion == 'd' || conversion == 'i')
	{
		num = va_arg(*ap, int);
		if (precision >= 0)
		{
			temp = num;
			u_num = 1;
			while (temp > 9)
			{
				temp /= 10;
				u_num++;
			}
			precision -= u_num;
			while (precision-- > 0)
				write(1, "0", sizeof(char));
		}
		ft_putnbr(num);
	}
	else if (conversion == 'u')
	{
		u_num = va_arg(*ap, unsigned int);
		ft_putnbr_unsigned(u_num);
	}
	else if (conversion == 'x' || conversion == 'X')
	{
		u_num = va_arg(*ap, unsigned int);
		(conversion == 'x') ? get_hex_and_print(u_num, hex) : get_hex_and_print(u_num, HEX);
	}
	else if (conversion == '%')
		write(1, "%", sizeof(char));
}

// [Comment] %를 만나면 conversion까지 읽어와 해당 조건에 맞게 출력하는 함수
int		replace_and_print(const char *format, int i, va_list *ap)
{
	int				j;
	char			*conversion;
	int				precision;

	// [Improving] Change to static varialbe and use ft_strlcpy funcion.
	conversion = "cspdiuxX%";
	while (format[i])
	{
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
	print_conversion(conversion[j], ap, precision);
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
			idx = replace_and_print(format, ++idx, &ap);
		else
			write(1, &format[idx], sizeof(char));
		idx++;
	}
	va_end(ap);
	return (0);
}
