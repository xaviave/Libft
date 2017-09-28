void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, '-', 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		write(1, (nb + 48), 1);
}
