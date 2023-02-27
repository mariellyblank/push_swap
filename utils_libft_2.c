#include "push_swap.h"

int	ft_count(const char *s, char c)
{
	int	i;
	int	chr;

	i = 0;
	chr = 0;
	while (*s)
	{
		if (*s != c && chr == 0)
		{
			chr = 1;
			i++;
		}
		else if (*s == c)
			chr = 0;
		s++;
	}
	return (i);
}

int	ft_str_size(char const *s, char c, size_t n)
{
	size_t	i;

	i = n;
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

int	ft_trim_size(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	x;

	i = n;
	x = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (x);
		i++;
		x++;
	}
	return (x);
}

char	*ft_cpy(char const *s, char *str, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) < len)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else if (start > ft_strlen(s))
		str = (char *)malloc(sizeof(char) * 1);
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	w_nbr;
	size_t	i;
	size_t	x;
	size_t	a;
	char	**str;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	w_nbr = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (w_nbr + 1));
	if (!str)
		return (NULL);
	while (i < w_nbr)
	{
		x = ft_trim_size(s, c, a);
		a = ft_str_size(s, c, a);
		str[i] = ft_cpy(s, *str, (unsigned int)(a - x), x);
		i++;
	}
	str[i] = NULL;
	return (str);
}
