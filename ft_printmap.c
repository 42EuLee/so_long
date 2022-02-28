#include "includes/so_long.h"

void	print_sidebar(t_data *data)
{
	int	i;
	int	j;
	int	legend;

	legend = data->map_w + 4;
	j = 0;
	data->y = 0;
	while (j < data->map_h)
	{
		i = data->map_w;
		data->x = (data->map_w - 1) * 32;
		while (i <= legend)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_bar.img,
				data->x, data->y);
			data->x += 32;
			i++;
		}
		j++;
		data->y += 32;
	}
}

void	draw_props(t_data *data, int j, int i)
{
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall.img,
			data->x, data->y);
	if (data->map[j][i] == 'P')
	{
		data->c_x = data->x / 32;
		data->c_y = data->y / 32;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_char.img,
			data->x, data->y);
	}
	if (data->map[j][i] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_item.img,
			data->x, data->y);
	if (data->map[j][i] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_exit.img,
			data->x, data->y);
}

void	ft_printmap(t_data *data)
{
	int	i;
	int	j;

	data->y = 0;
	j = 0;
	while (j < data->map_h)
	{
		i = 0;
		data->x = 0;
		while (i < data->map_w - 1)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->img_tile.img, data->x, data->y);
			draw_props(data, j, i);
			if ((data->map[j][i] == '<' || data->map[j][i] == '^'
				|| data->map[j][i] == '>' || data->map[j][i] == 'V'))
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_enemy.img, data->x, data->y);
			data->x += 32;
			i++;
		}
		j++;
		data->y += 32;
	}
	print_sidebar(data);
}
