#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
//	ft_printf("HI %%c is %c. and %%s is %s! thank you\n", 'a', "alphabet");
	ft_printf("%c%s%c\n", 'a', "bcd", 'e');
	return (0);
}
