#include "ft_printf.h"

int	count_size(unsigned long num)
{
	int	res;

	res = 0;
	if (!num)
		return (1);
	while (num)
	{
		res++;
		num /= 16;
	}
	return (res);
}

char	*to_hexademical(unsigned long num, char non_numeric_start)
{
	char	*res;
	int		size;
	int		i;

	size = count_size(num);
	res = ft_calloc(1, size + 1);
	if (!res)
		return (0);
	while (size)
	{
		i = num % 16;
		if (i >= 10)
			res[size - 1] = non_numeric_start + i - 10;
		else
			res[size - 1] = '0' + i;
		size--;
		num /= 16;
	}
	return (res);
}

int	do_x(va_list list, t_spec *spec)
{
	char				*new_val;
	unsigned int		num;

	num = va_arg(list, unsigned int);
	new_val = to_hexademical((unsigned long)num, 'a');
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}

int	do_p(va_list list, t_spec *spec)
{
	char				*hex_part;
	char				*new_val;
	unsigned long		num;

	num = va_arg(list, unsigned long);
	hex_part = to_hexademical(num, 'a');
	if (!hex_part)
		return (-1);
	new_val = ft_strjoin("0x", hex_part);
	free(hex_part);
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}

int	do_X(va_list list, t_spec *spec)
{
	char				*new_val;
	unsigned int		num;

	num = va_arg(list, unsigned int);
	new_val = to_hexademical((unsigned long)num, 'A');
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}
