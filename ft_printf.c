#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int	i;
	int	j;
	int	size;
	char	*conversion;
	char	c;
	char	*str;
	va_list	ap;

	// change to static varialbe and use ft_strlcpy funcion.
	conversion = "cspdiuxX%";
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			while (format[i] != conversion[j])
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
			if (conversion[j] == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, sizeof(char));
			}
			else if (conversion[j] == 's')
			{
				str = va_arg(ap, char *);
				size = 0;
				while (str[size])
					size++;
				write(1, str, (sizeof(char) * size));
			}
			else if (conversion[j] == 'p')
				continue ;
			else if (conversion[j] == 'd')
				continue ;
			else if (conversion[j] == 'i')
				continue ;
			else if (conversion[j] == 'u')
				continue ;
			else if (conversion[j] == 'x')
				continue ;
			else if (conversion[j] == 'X')
				continue ;
			else if (conversion[j] == '%')
				write(1, "%", sizeof(char));
		}
		else
			write(1, &format[i], sizeof(char));
		i++;
	}
	va_end(ap);
	return (0);
}
