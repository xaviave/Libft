#include <unistd.h>

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	write(1, '\n', 1);
}
