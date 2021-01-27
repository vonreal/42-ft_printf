#include <stdarg.h>
#include <unistd.h>

// conversion에 따라 출력하는 함수
void	print_conversion(char conversion, va_list *ap)
{
	char	c;
	char	*str;
	int		size;

	if (conversion == 'c')
	{
		c = va_arg(*ap, int);
		write(1, &c, sizeof(char));
	}
	else if (conversion == 's')
	{
		str = va_arg(*ap, char *);
		size = 0;
		while (str[size])
			size++;
		write(1, str, (sizeof(char) * size));
	}
	else if (conversion == 'p')
		continue ;
	else if (conversion == 'd')
		continue ;
	else if (conversion == 'i')
		continue ;
	else if (conversion == 'u')
		continue ;
	else if (conversion == 'x')
		continue ;
	else if (conversion == 'X')
		continue ;
	else if (conversion == '%')
		write(1, "%", sizeof(char));
}

// %를 만나면 conversion까지 읽어와 해당 조건에 맞게 출력하는 함수
int		replace_and_print(char *format, int i, va_list *ap)
{
	int		j;
	char	*conversion;

	// change to static varialbe and use ft_strlcpy funcion.
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
			idx = replace_and_print(format, idx, &ap);
		else
			write(1, &format[idx], sizeof(char));
		idx++;
	}
	va_end(ap);
	return (0);
}
