#include "./includes/so_long.h"

void	ft_add_items(int j, int i, t_data *data)
{
	if (data->map[j][i] == 'E')
		data->door = 1;
	if (data->map[j][i] == 'P')
		data->player++;
	if (data->map[j][i] == 'C')
		data->items++;
}

int	ft_check_items(t_data *data)
{
	if ((data->door == 0) || (data->player == 0) || (data->items == 0))
		return (0);
	return (1);
}

void	ft_check_border(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_w - 1)
	{
		if (data->map[0][i] != '1')
			return_error();
		if (data->map[data->map_h - 1][i] != '1')
			return_error();
		i++;
	}
	i = 0;
	while (i < data->map_h)
	{
		if (data->map[i][0] != '1')
			return_error();
		if (data->map[i][data->map_w - 2] != '1')
			return_error();
		i++;
	}
}

int	valid_char(t_data *data, int j, int i)
{
	if (data->map[j][i] != '1' && data->map[j][i] != 'E'
		&& data->map[j][i] != 'P' && data->map[j][i] != '0'
		&& data->map[j][i] != 'C' && data->map[j][i] != '<'
		&& data->map[j][i] != '^' && data->map[j][i] != '>'
		&& data->map[j][i] != 'V')
		return (0);
	return (1);
}

int	ft_check_valid(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_h)
	{
		i = 0;
		while (i < data->map_w - 1)
		{
			if (valid_char(data, j, i) == 0)
				return (0);
			ft_add_items(j, i, data);
			i++;
		}
		if (i != data->map_w - 1)
			return (0);
		j++;
	}
	if (ft_check_items(data) == 0)
		return (0);
	ft_check_border(data);
	return (1);
}
