
void	*ft_memset(void *s, int c, int n)
{
	int			i;
	unsigned char	*temp_s;
	int				temp_c;

	i = 0;
	temp_s = s;
	temp_c = c;
	while (i < n)
	{
		temp_s[i] = temp_c;
		i++;
	}
	temp_s[i] = '\0';
	return (s);
}