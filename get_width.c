#include "ft_printf.h"

int	get_width(const char *str, int *start)
{
	int		res;
	int		i;
	char	current;

	res = 0;
	i = 0;
	current = str[*start];
	if (current == '*')
	{
		*start += 1;
		return (-1);
	}
	while (ft_isdigit(current))
	{
		i++;
		current = str[*start + i];
	}
	if (i)
		res = ft_natoi((char *)str + *start, i);
	*start += i;
	return (res);
}
