#include <stdio.h>
#include <stdarg.h>

int	get_count(const char *str)
{
	int idx;
	int count;

	count = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '%')
			count++;
		idx++;
	}
	return (count);

}

int	ft_printf(const char *str, ...)
{
	int count;
	int idx;
	va_list ap;

	count = get_count(str);
	va_start(ap, count);
	idx = 0;
	while (idx < count)
	{
		printf("%d ", va_arg(ap, int));
		idx++;
	}
	va_end(ap);
	printf("\n");
	return (0);

}

void	main(void)
{
	ft_printf(" ");
	ft_printf("%", 1);
	ft_printf("% %", 1, 2);
	ft_printf("% % %", 1, 2, 3);
}
