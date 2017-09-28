char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (needle[k])
		k++;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == k - 1)
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
