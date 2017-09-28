void	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}
