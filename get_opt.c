#include "ft_printf.h"

char	get_opt(const char *str, int *start)
{
	char	c;

	c = str[*start];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		*start += 1;
		return (c);
	}
	return (0);
}
