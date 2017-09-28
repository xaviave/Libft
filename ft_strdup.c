#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int	i;
	char	*out;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(out = malloc(sizeof((char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		out[i] = s[i];
		i++;
	}
	return (out);
}
