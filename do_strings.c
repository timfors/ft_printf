#include "ft_printf.h"

int	do_c(va_list list, t_spec *spec)
{
	char	*new_val;

	new_val = ft_calloc(1, 2);
	if (!new_val)
		return (-1);
	new_val[0] = va_arg(list, int);
	change_spec_val(spec, new_val);
	return (0);
}

int	do_s(va_list list, t_spec *spec)
{
	char	*new_val;
	char	*arg_val;

	arg_val = va_arg(list, char *);
	if (!arg_val)
	{
		new_val = ft_calloc(1, 7);
		if (!new_val)
			return (-1);
		ft_strlcpy(new_val, "(null)", 7);
	}
	else
	{
		new_val = ft_strdup(arg_val);
		if (!new_val)
			return (-1);
	}
	change_spec_val(spec, new_val);
	return (0);
}

int	do_percent(t_spec *spec)
{
	char	*new_val;

	new_val = ft_calloc(1, 2);
	if (!new_val)
		return (-1);
	new_val[0] = '%';
	change_spec_val(spec, new_val);
	return (0);
}
