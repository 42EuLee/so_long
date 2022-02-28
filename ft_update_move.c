#include "./includes/so_long.h"

void	valid_move(int key, t_data *data, int j, int i)
{
	if (key == 13 && (data->map[j - 1][i] == '0' && data->cd == 0))
	{
		data->map[j - 1][i] = 'P';
		data->map[j][i] = '0';
		data->moves++;
	}
	else if (key == 0 && (data->map[j][i - 1] == '0' && data->cd == 0))
	{
		data->map[j][i - 1] = 'P';
		data->map[j][i] = '0';
		data->moves++;
	}
	else if (key == 1 && (data->map[j + 1][i] == '0' && data->cd == 0))
	{
		data->map[j + 1][i] = 'P';
		data->map[j][i] = '0';
		data->moves++;
	}
	else if (key == 2 && (data->map[j][i + 1] == '0' && data->cd == 0))
	{
		data->map[j][i + 1] = 'P';
		data->map[j][i] = '0';
		data->moves++;
	}
	data->cd = 1;
}

int	is_door(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->c_x;
	j = data->c_y;
	if (key == 13 && (data->map[j - 1][i] == 'E'))
		return (0);
	else if (key == 0 && (data->map[j][i - 1] == 'E'))
		return (0);
	else if (key == 1 && (data->map[j + 1][i] == 'E'))
		return (0);
	else if (key == 2 && (data->map[j][i + 1] == 'E'))
		return (0);
	return (1);
}

void	ft_update_move(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->c_x;
	j = data->c_y;
	if (data->bang == 0)
	{
		if (is_door(key, data) == 0)
			data->map[j][i] = 'P';
		else
			valid_move(key, data, j, i);
	}
}
