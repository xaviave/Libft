#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == c)
		return (s[i]);
	else
		i++;
	return (NULL);
}
