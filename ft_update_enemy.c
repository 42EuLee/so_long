#include "./includes/so_long.h"

void	ft_enemy_down(char **map, int j, int i)
{
	if (map[j + 1][i] == '0')
	{
		map[j + 1][i] = 'V';
		map[j][i] = '0';
	}
	else if (map[j + 1][i] != '0')
	{
		map[j][i] = '^';
	}
}

void	ft_enemy_up(char **map, int j, int i)
{
	if (map[j - 1][i] == '0')
	{
		map[j - 1][i] = '^';
		map[j][i] = '0';
	}
	else if (map[j - 1][i] != '0')
	{
		map[j][i] = 'V';
	}
}

void	ft_enemy_right(char **map, int j, int i)
{
	if (map[j][i + 1] == '0')
	{
		map[j][i + 1] = '>';
		map[j][i] = '0';
	}
	else if (map[j][i + 1] != '0')
	{
		map[j][i] = '<';
	}
}

void	ft_enemy_left(char **map, int j, int i)
{
	if (map[j][i - 1] == '0')
	{
		map[j][i - 1] = '<';
		map[j][i] = '0';
	}
	else if (map[j][i - 1] != '0')
	{
		map[j][i] = '>';
	}
}

char	**ft_update_enemy(char **map, int j, int i)
{
	if (map[j][i] == '<')
		ft_enemy_left(map, j, i);
	else if (map[j][i] == '>')
		ft_enemy_right(map, j, i);
	else if (map[j][i] == '^')
		ft_enemy_up(map, j, i);
	else if (map[j][i] == 'V' )
		ft_enemy_down(map, j, i);
	return (map);
}
