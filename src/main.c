
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_info	info;

	program_validator(ac, av);
	parser(&info, av[1]);
	executor(&info);
	return (0);
}
