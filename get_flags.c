#include "ft_printf.h"

static int	is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

static void	add_flag(char *res, char c)
{
	int	i;

	i = 0;
	while (res[i] && i < FLAGS_COUNT)
		i++;
	if (i < FLAGS_COUNT)
		res[i] = c;
}

char	*get_flags(const char *str, int *start)
{
	int		i;
	char	*res;
	char	current;

	i = 1;
	res = ft_calloc(1, FLAGS_COUNT + 1);
	if (!res)
		return (0);
	while (is_flag(str[*start + i]))
	{
		current = str[*start + i];
		if (!ft_strchr(res, current))
			add_flag(res, current);
		i++;
	}
	*start += i;
	return (res);
}
