#include "ft_printf.h"

char	*add_chars_right(const char *str, char c, int size)
{
	char	*res;
	char	*extra_part;

	if (size < 0)
		return (0);
	extra_part = ft_calloc(1, size + 1);
	if (!extra_part)
		return (0);
	while (size > 0)
		extra_part[(size--) - 1] = c;
	res = ft_strjoin(str, extra_part);
	if (!res)
		return (0);
	free(extra_part);
	return (res);
}

char	*add_chars_left(const char *str, char c, int size)
{
	char	*res;
	char	*extra_part;

	if (size < 0)
		return (0);
	extra_part = ft_calloc(1, size + 1);
	if (!extra_part)
		return (0);
	while (size > 0)
		extra_part[(size--) - 1] = c;
	res = ft_strjoin(extra_part, str);
	if (!res)
		return (0);
	free(extra_part);
	return (res);
}
