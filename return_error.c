#include "push_swap.h"

void	error_message(int ac, char **av)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (i < ac)
	{
		while (av[i][y] != '\0')
		{
			if (!ft_isdigit(av[i][y]) && av[i][y] != ' ' && av[i][y] != '-')
				exit (write(2,"ERROR\n", 6));
		}
		y++;
	}
	y = 0;
	i++;
}
