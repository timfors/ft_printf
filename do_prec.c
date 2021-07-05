#include "ft_printf.h"

int	do_prec_s(t_spec *spec)
{
	if (!spec)
		return (-1);
	if ((int)ft_strlen(spec->str_val) > spec->precision)
	{
		spec->str_val[spec->precision] = 0;
		spec->str_len = spec->precision;
	}
	return (0);
}

static int	set_zero(t_spec *spec)
{
	char	*new_val;

	new_val = ft_calloc(1, 1);
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	spec->str_len = 0;
	return (0);
}

int	do_prec_int(t_spec *spec)
{
	int		extra_size;
	char	*new_val;

	if (spec->precision == 0 && spec->str_val[0] == '0')
		return (set_zero(spec));
	extra_size = spec->precision - spec->str_len;
	if (spec->str_val[0] == '-')
		extra_size++;
	if (extra_size <= 0)
		return (0);
	spec->str_len += extra_size;
	new_val = add_chars_left(spec->str_val, '0', extra_size);
	if (!new_val)
		return (-1);
	if (spec->str_val[0] == '-')
	{
		new_val[0] = '-';
		new_val[extra_size] = '0';
	}
	change_spec_val(spec, new_val);
	return (0);
}
