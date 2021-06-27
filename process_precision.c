#include "ft_printf.h"

int	process_precision(va_list list, t_spec spec)
{
	int	res;

	if (spec.opt == 's')
		res = do_prec_s(spec);
	else if (spec.opt == 'd')
		res = do_prec_s(spec);
	else if (spec.opt == 'i')
		res = do_prec_i(spec);
	else if (spec.opt == 'u')
		res = do_prec_u(spec);
	else if (spec.opt == 'x')
		res = do_prec_x(spec);
	else if (spec.opt == 'X')
		res = do_prec_X(spec);
	else
		res = 0;
	return (res);
}
