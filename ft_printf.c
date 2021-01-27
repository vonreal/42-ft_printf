#include <stdarg.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char num;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * (-1), 1);
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

void	get_hex_and_print(int n, char *hex)
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
void	print_conversion(char conversion, va_list *ap)
{
	char	c;
	char	*str;
	char	hex[17] = "0123456789abcdef";
	char	HEX[17] = "0123456789ABCDEF";
	int		num;

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
		return ;
	else if (conversion == 'd' || conversion == 'i')
	{
		num = va_arg(*ap, int);
		ft_putnbr(num);
	}
	else if (conversion == 'u')
		return ;
	else if (conversion == 'x' || conversion == 'X')
	{
		num = va_arg(*ap, int);
		(conversion == 'x') ? get_hex_and_print(num, hex) : get_hex_and_print(num, HEX);
	}
	else if (conversion == '%')
		write(1, "%", sizeof(char));
}

// [Comment] %를 만나면 conversion까지 읽어와 해당 조건에 맞게 출력하는 함수
int		replace_and_print(const char *format, int i, va_list *ap)
{
	int		j;
	char	*conversion;

	// [Improving] Change to static varialbe and use ft_strlcpy funcion.
	conversion = "cspdiuxX%";
	while (format[i])
	{
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
	print_conversion(conversion[j], ap);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		idx;
	va_list	ap;

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
