#include "./includes/so_long.h"

void	death_quote(void)
{
	ft_putstr("-----------------------------------------\n");
	ft_putstr("You died, git gud and try again.\n");
	ft_putstr("-----------------------------------------\n");
}

void	ft_print_sidebar(t_data *data)
{
	char	*c;

	c = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->mlx_win, (data->map_w * 32) - 24,
		data->map_h, 1, "Moves:");
	mlx_string_put(data->mlx, data->mlx_win, (data->map_w + 1.5) * 32,
		data->map_h, 1, c);
	free(c);
	c = ft_itoa(data->items);
	mlx_string_put(data->mlx, data->mlx_win, (data->map_w * 32) - 24,
		data->map_h + 32, 1, "Items:");
	mlx_string_put(data->mlx, data->mlx_win, (data->map_w + 1.5) * 32,
		data->map_h + 32, 1, c);
	free(c);
	if (data->items == 0 && data->bang == 0)
	{
		mlx_string_put(data->mlx, data->mlx_win, (data->map_w * 32) - 24,
			data->map_h + 64, 1, "Door is opened!");
	}
	if (data->bang > 1)
		mlx_string_put(data->mlx, data->mlx_win, (data->map_w) * 32,
			data->map_h + 64, 1, "YOU DIED");
}

int	key_hook(int key, t_data *data)
{
	ft_finish_game(key, data);
	ft_update_move(key, data);
	if_bang_enemy(key, data);
	if_bang_enemy2(key, data);
	ft_count_items(key, data);
	if (key == 53)
		exit_game(data);
	return (0);
}

int	ft_render_loop(t_data *data, int img_width, int img_height)
{
	ft_check_enemy(data);
	data->frame++;
	ft_print_sidebar(data);
	if (data->cd != 0)
		data->cd--;
	if (data->bang == 0)
		ft_player_bob(data, img_width, img_height);
	if (data->bang > 0)
	{
		ft_player_death(data, img_width, img_height);
		data->bang++;
		if (data->bang == 220)
		{
			death_quote();
			exit_game(data);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		img_width;
	int		img_height;

	if (argc != 2)
		return (0);
	img_width = 0;
	img_height = 0;
	data.mlx = mlx_init();
	createcords(&data);
	ft_readinputs(&data, argv);
	data.mlx_win = mlx_new_window(data.mlx, (data.map_w + 4) * 32,
			data.map_h * 32, "so_long");
	ft_get_images(&data, img_width, img_height);
	mlx_hook(data.mlx_win, 17, 0, exit_game, &data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop_hook(data.mlx, ft_render_loop, &data);
	mlx_loop(data.mlx);
}
