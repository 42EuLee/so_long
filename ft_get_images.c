#include "./includes/so_long.h"

void	ft_get_bonus_img(t_data *data, int img_width, int img_height)
{
	char	*rp6;
	char	*rp7;

	rp6 = "./assets/redhood.xpm";
	rp7 = "./assets/legend.xpm";
	data->img_enemy.img = mlx_xpm_file_to_image(data->mlx, rp6, &img_width,
			&img_height);
	data->img_bar.img = mlx_xpm_file_to_image(data->mlx, rp7, &img_width,
			&img_height);
}

void	ft_get_images(t_data *data, int img_width, int img_height)
{
	char	*rp;
	char	*rp2;
	char	*rp3;
	char	*rp4;
	char	*rp5;

	rp = "./assets/wall.xpm";
	rp2 = "./assets/tile.xpm";
	rp3 = "./assets/char.xpm";
	rp4 = "./assets/item.xpm";
	rp5 = "./assets/exit.xpm";
	data->img_wall.img = mlx_xpm_file_to_image(data->mlx, rp, &img_width,
			&img_height);
	data->img_tile.img = mlx_xpm_file_to_image(data->mlx, rp2, &img_width,
			&img_height);
	data->img_char.img = mlx_xpm_file_to_image(data->mlx, rp3, &img_width,
			&img_height);
	data->img_item.img = mlx_xpm_file_to_image(data->mlx, rp4, &img_width,
			&img_height);
	data->img_exit.img = mlx_xpm_file_to_image(data->mlx, rp5, &img_width,
			&img_height);
	ft_get_bonus_img(data, img_width, img_height);
}
