#include "ft_printf.h"

int	get_precision(const char *str, int *start)
{
	int		i;
	int		res;
	char	current;

	if (str[*start] != '.')
		return (-2);
	i = 1;
	res = 0;
	current = str[*start + i];
	if (current == '*')
	{
		*start += 2;
		return (-1);
	}
	while (ft_isdigit(current))
	{
		i++;
		current = str[*start + i];
	}
	if (i > 1)
		res = ft_natoi((char *)str + *start + 1, i - 1);
	*start += i;
	return (res);
}
