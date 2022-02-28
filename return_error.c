#include "./includes/so_long.h"

void	return_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
