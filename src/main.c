
#include "cub3d.h"

void leaks() {
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_info	info;

	program_validator(ac, av);
	parser(&info, av[1]);
	executor(&info);
	atexit(leaks);
	return (0);
}
