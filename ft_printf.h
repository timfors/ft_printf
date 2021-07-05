#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS_COUNT 2

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
typedef struct s_spec
{
	char	*flags;
	int		width;
	int		precision;
	char	option;
	char	*str_val;
	int		str_len;
}	t_spec;

void	change_spec_val(t_spec *spec, char *new_val);
void	free_spec(t_spec *spec);
int		is_digit_option(t_spec *spec);

int		ft_printf(const char *input, ...);
int		process_spec(va_list list, t_spec *spec);
t_spec	*init_spec(const char *str, int *start);
char	*get_flags(const char *str, int *start);
int		get_width(const char *str, int *start);
int		get_precision(const char *str, int *start);
char	get_opt(const char *str, int *start);

int		process_opt(va_list list, t_spec *spec);
int		process_width(t_spec *spec);
int		process_precision(t_spec *spec);

int		do_c(va_list list, t_spec *spec);
int		do_s(va_list list, t_spec *spec);
int		do_p(va_list list, t_spec *spec);
int		do_d(va_list list, t_spec *spec);
int		do_i(va_list list, t_spec *spec);
int		do_u(va_list list, t_spec *spec);
int		do_x(va_list list, t_spec *spec);
int		do_X(va_list list, t_spec *spec);
int		do_percent(t_spec *spec);

int		do_prec_s(t_spec *spec);
int		do_prec_int(t_spec *spec);

char	*add_chars_right(const char *str, char c, int size);
char	*add_chars_left(const char *str, char c, int size);
#endif	
