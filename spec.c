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

void	free_spec(t_spec *spec)
{
	if (spec->flags)
		free(spec->flags);
	if (spec->str_val)
		free(spec->str_val);
	free(spec);
}
