#include "./includes/so_long.h"

int	exit_game(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->img_wall.img);
	mlx_destroy_image(data->mlx, data->img_char.img);
	mlx_destroy_image(data->mlx, data->img_exit.img);
	mlx_destroy_image(data->mlx, data->img_item.img);
	mlx_destroy_image(data->mlx, data->img_tile.img);
	mlx_destroy_image(data->mlx, data->img_enemy.img);
	mlx_destroy_image(data->mlx, data->img_bar.img);
	i = 0;
	while (i < data->map_h)
		free(data->map[i++]);
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}
