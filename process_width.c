#include "ft_printf.h"

int	do_width_default(t_spec *spec)
{
	int		extra_size;
	char	*new_val;

	extra_size = spec->width - spec->str_len;
	if (extra_size <= 0)
		return (0);
	spec->str_len += extra_size;
	new_val = add_chars_left(spec->str_val, ' ', extra_size);
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}

int	do_width_minus_c(t_spec *spec)
{
	int		extra_size;
	char	*new_val;

	extra_size = spec->width - spec->str_len;
	if (extra_size <= 0)
		return (0);
	spec->str_len += extra_size;
	new_val = ft_calloc(1, extra_size + 2);
	if (!new_val)
		return (-1);
	new_val[0] = spec->str_val[0];
	while (extra_size)
		new_val[extra_size--] = ' ';
	change_spec_val(spec, new_val);
	return (0);
}

int	do_width_minus(t_spec *spec)
{
	int		extra_size;
	char	*new_val;

	extra_size = spec->width - spec->str_len;
	if (extra_size <= 0)
		return (0);
	spec->str_len += extra_size;
	new_val = add_chars_right(spec->str_val, ' ', extra_size);
	if (!new_val)
		return (-1);
	change_spec_val(spec, new_val);
	return (0);
}

int	do_width_zero(t_spec *spec)
{
	int		extra_size;
	char	*new_val;

	extra_size = spec->width - spec->str_len;
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

int	process_width(t_spec *spec)
{
	int		res;

	if (spec->width < 0)
	{
		spec->width *= -1;
		if (!ft_strchr(spec->flags, '-'))
			spec->flags[ft_strlen(spec->flags)] = '-';
	}
	if (ft_strchr(spec->flags, '-') && spec->option == 'c')
		res = do_width_minus_c(spec);
	else if (ft_strchr(spec->flags, '-'))
		res = do_width_minus(spec);
	else if (ft_strchr(spec->flags, '0') && !(spec->precision >= 0
			&& is_digit_option(spec)))
		res = do_width_zero(spec);
	else
		res = do_width_default(spec);
	return (res);
}
