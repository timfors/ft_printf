#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int i;
	t_spec	spec;

	if (argc != 2)
	{
		printf("Enter 1 string!\n");
		return (0);
	}
	i = 0;
	spec = *init_spec(argv[1], &i);
	printf("FLAGS:\t\t%s\n", spec.flags);
	printf("WIDTH:\t\t%d\n", spec.width);
	printf("PRECISION:\t%d\n", spec.precision);
	printf("OPTIONT:\t%c\n", spec.option);
}
