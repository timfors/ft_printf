#include "ft_printf.h"

int	process_opt(va_list list, t_spec spec)
{
	int	res;

	res = -1;
	if (spec.opt == 'c')
		res = do_c(list, spec);
	else if (spec.opt == 's')
		res = do_s(list, spec);
	else if (spec.opt == 'p')
		res = do_p(list, spec);
	else if (spec.opt == 'd')
		res = do_d(list, spec);
	else if (spec.opt == 'i')
		res = do_i(list, spec);
	else if (spec.opt == 'u')
		res = do_u(list, spec);
	else if (spec.opt == 'x')
		res = do_x(list, spec);
	else if (spec.opt == 'X')
		res = do_X(list, spec);
	else if (spec.opt == '%')
		res = do_X(list, spec);
	return (res);
}
