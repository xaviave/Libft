int	ft_atoi(const char *nptr)
{
	int	i;
	char	n;
	int	out;

	i = 0;
	out = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		n = nptr[i++];
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = out * 10 + nptr[i] - 48;
		i++;
	}
	return (out);
}
