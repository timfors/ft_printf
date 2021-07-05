#include "ft_printf.h"

size_t static	calc_size(unsigned long long n)
{
	size_t	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

void static	iter(char *res, unsigned long long n, size_t size)
{
	res[size] = n % 10 + '0';
	if (size == 0)
		return ;
	iter(res, n / 10, size - 1);
}

static char	*ull_to_a(unsigned long long n)
{
	size_t	size;
	char	*res;

	size = calc_size(n);
	res = ft_calloc(1, size + 1);
	if (!res)
		return (0);
	iter(res, n, size - 1);
	return (res);
}

int	do_u(va_list list, t_spec *spec)
{
	char			*new_val;
	unsigned int	num;

	num = va_arg(list, unsigned int);
	new_val = ull_to_a(num);
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}
