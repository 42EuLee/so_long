#include "./includes/so_long.h"

void	ft_count_items2(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->c_x;
	j = data->c_y;
	if (key == 1 && (data->map[j + 1][i] == 'C'))
	{
		data->map[j][i] = '0';
		data->map[j + 1][i] = 'P';
		data->items--;
	}
	if (key == 2 && (data->map[j][i + 1] == 'C'))
	{
		data->map[j][i] = '0';
		data->map[j][i + 1] = 'P';
		data->items--;
	}
}

void	ft_count_items(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->c_x;
	j = data->c_y;
	if (key == 13 && (data->map[j - 1][i] == 'C'))
	{
		data->map[j][i] = '0';
		data->map[j - 1][i] = 'P';
		data->items--;
	}
	if (key == 0 && (data->map[j][i - 1] == 'C'))
	{
		data->map[j][i] = '0';
		data->map[j][i - 1] = 'P';
		data->items--;
	}
	ft_count_items2(key, data);
}
