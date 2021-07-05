#include "ft_printf.h"

t_spec	*init_spec(const char *str, int *start)
{
	t_spec	*result;

	result = ft_calloc(1, sizeof(t_spec));
	if (!result)
		return (0);
	result->flags = get_flags(str, start);
	if (!result->flags)
	{
		free_spec(result);
		return (0);
	}
	result->width = get_width(str, start);
	result->precision = get_precision(str, start);
	result->option = get_opt(str, start);
	return (result);
}

void	change_spec_val(t_spec *spec, char *new_val)
{
	if (spec->str_val)
		free(spec->str_val);
	spec->str_val = new_val;
}

void	free_spec(t_spec *spec)
{
	if (spec->flags)
		free(spec->flags);
	if (spec->str_val)
		free(spec->str_val);
	free(spec);
}

int	is_digit_option(t_spec *spec)
{
	return (spec->option == 'x' || spec->option == 'X'
		|| spec->option == 'd' || spec->option == 'i'
		|| spec->option == 'u' || spec->option == 'o');
}
