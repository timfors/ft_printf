#include "ft_printf.h"

int	process_opt(va_list list, t_spec *spec)
{
	int	res;

	res = -1;
	if (spec->option == 'c')
		res = do_c(list, spec);
	else if (spec->option == 's')
		res = do_s(list, spec);
	else if (spec->option == 'p')
		res = do_p(list, spec);
	else if (spec->option == 'd')
		res = do_d(list, spec);
	else if (spec->option == 'i')
		res = do_i(list, spec);
	else if (spec->option == 'u')
		res = do_u(list, spec);
	else if (spec->option == 'x')
		res = do_x(list, spec);
	else if (spec->option == 'X')
		res = do_X(list, spec);
	else if (spec->option == '%')
		res = do_percent(spec);
	spec->str_len += ft_strlen(spec->str_val);
	if (!spec->str_len && spec->option == 'c')
		spec->str_len = 1;
	return (res);
}
