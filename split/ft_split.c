#include "../push_swap.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			++count;
		}
		++i;
	}
	return (count);
}

void	free_split(char **res, int k)
{
	int	i;

	if (!res) // ✅ Evita liberar un NULL
		return;
	i = 0;
	while (i < k)
	{
		if (res[i]) // ✅ Evita liberar memoria ya liberada
			free(res[i]);
		i++;
	}
	free(res);
}

static int	fill_split(const char *s, char c, char **res)
{
	int	cont[3];

	cont[0] = 0;
	cont[2] = 0;
	while (*(s + cont[0]))
	{
		while (*(s + cont[0]) == c)
			++cont[0];
		cont[1] = 0;
		while (*(s + cont[0] + cont[1]) && *(s + cont[0] + cont[1]) != c)
			++cont[1];
		if (cont[1] > 0)
		{
			res[cont[2]] = ft_substr(s, cont[0], cont[1]);
			if (res[cont[2]] == NULL)
			{
				free_split(res, cont[2]);
				return (-1);
			}
			++cont[2];
		}
		cont[0] += cont[1];
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**res;

	words = word_count(s, c);
	res = (char **) malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[words] = NULL;
	if (fill_split(s, c, res) == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
