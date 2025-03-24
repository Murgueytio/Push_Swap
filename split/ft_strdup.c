#include "../push_swap.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	if (dest == 0)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
