#include "ft_printf.h"

int	process_precision(t_spec *spec)
{
	int	res;

	if (spec->precision < 0)
		return (0);
	if (spec->option == 's')
		res = do_prec_s(spec);
	else if (spec->option == 'd')
		res = do_prec_int(spec);
	else if (spec->option == 'i')
		res = do_prec_int(spec);
	else if (spec->option == 'u')
		res = do_prec_int(spec);
	else if (spec->option == 'x')
		res = do_prec_int(spec);
	else if (spec->option == 'X')
		res = do_prec_int(spec);
	else
		res = 0;
	return (res);
}
