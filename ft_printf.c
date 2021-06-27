#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int		start;
	int		last;
	int		res;
	va_list	list;
	t_spec	*spec;

	start = 0;
	end = 0;
	res = 0;
	va_start(list, input);
	last = 0;
	while (find_next_spec(input, &start))
	{
		write(1, (char *)input + last, start - last);
		res += start - last;
		spec = init_spec(input, &start);
		if (process_spec(list, *spec) == -1)
			return (-1);
		if (spec->opt)
			last = start;
		free(spec);
	}
	write(1, (char *)input + last, start - last);
	res += start - last;
	return (res);
}
