#include <iostream>
#include <ctype.h>

std::string call()
{
	std::string temp = "Bomber";
	std::cout << "Addr: " << &temp << std::endl;
	return (temp);
}


int	main(int ac, char **av)
{
	int		i = 1;
	int		j = 0;
	char	c;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (islower(av[i][j]))
			{
				c = toupper(av[i][j]);
				std::cout << c;
			}
			else
				std::cout << av[i][j];
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}