#include "./includes/so_long.h"

void	ft_game_end(t_data *data)
{
	char	*str;

	ft_putstr("-----------------------------------------\n");
	ft_putstr("Congratulations, you completed the game!\n");
	str = ft_itoa(data->moves);
	ft_putstr("Total moves made: ");
	ft_putstr(str);
	ft_putstr("\n-----------------------------------------\n");
	free(str);
}

void	ft_finish_game2(int key, t_data	*data)
{
	int	i;
	int	j;

	i = data->c_x;
	j = data->c_y;
	if (key == 13 && (data->map[j - 1][i] == 'E'))
	{
		data->map[j - 1][i] = 'P';
		data->door--;
	}
	else if (key == 0 && (data->map[j][i - 1] == 'E'))
	{
		data->map[j][i - 1] = 'P';
		data->door--;
	}
}

void	ft_finish_game(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->c_x;
	j = data->c_y;
	if (data->items == 0)
	{
		ft_finish_game2(key, data);
		if (key == 1 && (data->map[j + 1][i] == 'E'))
		{
			data->map[j + 1][i] = 'P';
			data->door--;
		}
		else if (key == 2 && (data->map[j][i + 1] == 'E'))
		{
			data->map[j][i + 1] = 'P';
			data->door--;
		}
		if (data->door == 0)
		{
			ft_game_end(data);
			exit_game(data);
		}
	}
}
