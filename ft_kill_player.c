#include "./includes/so_long.h"

char	**ft_kill_up(t_data *data, char **map, int j, int i)
{
	if (map[j - 1][i] == 'P')
	{
		map[j][i] = '0';
		data->bang = 1;
	}
	return (map);
}

char	**ft_kill_down(t_data *data, char **map, int j, int i)
{
	if (map[j + 1][i] == 'P')
	{
		map[j][i] = '0';
		data->bang = 1;
	}
	return (map);
}

char	**ft_kill_left(t_data *data, char **map, int j, int i)
{
	if (map[j][i - 1] == 'P')
	{
		map[j][i] = '0';
		data->bang = 1;
	}
	return (map);
}

char	**ft_kill_right(t_data *data, char **map, int j, int i)
{
	if (map[j][i + 1] == 'P')
	{
		map[j][i] = '0';
		data->bang = 1;
	}
	return (map);
}

char	**ft_kill_player(t_data *data, char **map, int j, int i)
{
	if (map[j][i] == '<')
		ft_kill_left(data, map, j, i);
	else if (map[j][i] == '>')
		ft_kill_right(data, map, j, i);
	else if (map[j][i] == '^')
		ft_kill_up(data, map, j, i);
	else if (map[j][i] == 'V')
		ft_kill_down(data, map, j, i);
	return (map);
}
