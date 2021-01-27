#include <stdio.h>
#include <stdarg.h>

void	foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == 's')
			printf("%s", va_arg(ap, char *));
		else if (*fmt == 'c')
			printf("%c", va_arg(ap, int));
		else if (*fmt == 'd')
			printf("%d", va_arg(ap, int));
		*fmt++;
	}
	printf("\n");
	va_end(ap);
}

void	main(void)
{
	foo("c, s, c", 'a', "bcd", 'e');
}
