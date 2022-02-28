#include "./includes/so_long.h"

void	free_dup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_h)
		free(data->map[i++]);
	free(data->map);
}

void	if_enemy(char **map, t_data *data, int j, int i)
{
	if (data->map[j][i] == '<' || data->map[j][i] == '^'
		|| data->map[j][i] == '>' || data->map[j][i] == 'V')
	{
		map = ft_kill_player(data, map, j, i);
		if (data->bang == 0)
			map = ft_update_enemy(map, j, i);
	}
}

void	ft_check_enemy(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = ft_mapdup(data);
	j = 0;
	data->count++;
	if (data->count == 30)
	{
		while (j < data->map_h)
		{
			i = 0;
			while (i < data->map_w - 1)
			{
				if_enemy(map, data, j, i);
				i++;
			}
			j++;
		}
		data->count = 0;
	}
	i = 0;
	free_dup(data);
	data->map = map;
	ft_printmap(data);
}
