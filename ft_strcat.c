char	*ft_strcat(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
