#include <iostream>

char	*ft_uppercase(char *c)
{
	int i = 0;
	while (c && c[i])
	{
		if ('a' <= c[i] && c[i] <= 'z')
			c[i]-=32;
		i++;
	}
	return (c);
}

int	main(int ac, char **av)
{
	int	i = 0;
	while (++i < ac)
			std::cout << ft_uppercase(av[i]);
	std::cout << '\n';
	return (0);
}