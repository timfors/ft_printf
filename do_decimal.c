#include "ft_printf.h"

int	do_d(va_list list, t_spec *spec)
{
	char	*new_val;
	int		num;

	num = va_arg(list, int);
	new_val = ft_itoa(num);
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}

int	do_i(va_list list, t_spec *spec)
{
	return (do_d(list, spec));
}
