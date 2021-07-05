#include "ft_printf.h"

static void	write_count_step(char *str, int count, int *res)
{
	write(1, str, count);
	*res += count;
}

static int	finish(va_list list, int res)
{
	va_end(list);
	return (res);
}

static int	find_next_spec(const char *str, int *start)
{
	if (!str || !start)
		return (-1);
	while (str[*start])
	{
		if (str[*start] == '%')
			return (1);
		*start += 1;
	}
	return (0);
}

static void	init_params(int *start, int *last, int *res)
{
	*start = 0;
	*last = 0;
	*res = 0;
}

int	ft_printf(const char *input, ...)
{
	int		start;
	int		last;
	int		res;
	va_list	list;
	t_spec	*spec;

	if (!input)
		return (-1);
	init_params(&start, &last, &res);
	va_start(list, input);
	while (find_next_spec(input, &start) > 0)
	{
		write_count_step((char *)input + last, start - last, &res);
		spec = init_spec(input, &start);
		if (process_spec(list, spec) == -1)
			return (finish(list, -1));
		if (spec->option)
		{
			last = start;
			res += spec->str_len;
		}
		free_spec(spec);
	}
	write_count_step((char *)input + last, start - last, &res);
	return (finish(list, res));
}
