#include "ft_printf.h"

int	process_width(va_list list, t_spec spec)
{
	int	res;

	if (!spec.flags[0])
		res = do_width_default(spec);
	if (ft_strchar(spec.flags, '-'))
		res = do_width_minus(spec);
	else if (ft_strchar(spec.flags), '0')
		res = do_width_zero(spec);
	return (res);
}

int	do_width_default(t_spec spec)
{
	return (0);
}
