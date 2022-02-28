#include "./includes/so_long.h"

char	**ft_mapdup(t_data *data)
{
	int		i;
	char	**heap;

	heap = (char **)malloc(sizeof(char *) * (data->map_h + 1));
	if (!heap)
		return (NULL);
	i = 0;
	while (i < data->map_h)
	{
		heap[i] = ft_strndup(data->map[i], data->map_w);
		i++;
	}
	heap[i] = NULL;
	return (heap);
}
