int	ft_isalnum(int c)
{
	int i;

	i = 0;
	if (ft_isdigit(c) == 1)
		return (1);
	if (ft_isalpha(c) == 1)
		return (1);
	return (0);
}
