#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int		ft_printf(const char *input, ...);
int		find_next_spec(const char *str, int *start);
int		process_spec(const char *str, va_list list, t_spec spec);
t_spec	*init_spec(const char *str, int *start);
char	*get_flags(const char *str, int *start);
int		get_width(const char *str, int *start);
int		get_precision(const char *str, int *start);
char	*get_opt(const char *str, int *start);
void	free_spec(t_spec *spec);
#endif	
