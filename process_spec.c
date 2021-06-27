#include "ft_printf.h"

int	process_spec(va_list list, t_spec spec)
{
	if (!spec.opt)
	{
		free_spec(spec);
		return (-1);
	}
	if (spec.width == -1)
		spec.width = va_arg(list, int);
	if (spec.precision == -1)
		spec.precision = va_arg(list, int);
	if (process_opt(list, spec) == -1
		|| process_precision(list, spec) == -1
		|| process_width(list, spec) == -1)
	{
		free_spec(spec);
		return (-1);
	}
	write(1, spec.str_val, ft_strlen(spec.str_val));
	return (0);
}
