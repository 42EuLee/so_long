#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_enemy
{	
	void	*enemy;
	int		x;
	int		y;
}	t_enemy;

typedef struct s_tex
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_tex;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_tex	img_wall;
	t_tex	img_char;
	t_tex	img_exit;
	t_tex	img_item;
	t_tex	img_tile;
	t_tex	img_enemy;
	t_tex	img_bar;
	char	**map;
	int		map_h;
	int		map_w;
	int		x;
	int		y;
	int		c_x;
	int		c_y;
	int		items;
	int		door;
	int		moves;
	int		player;
	int		frame;
	int		window_height;
	int		window_width;
	int		bang;
	int		count;
	int		turn;
	int		turn2;
	int		cd;
	int		died;
}	t_data;

void	ft_printmap(t_data *data);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	return_error(void);
void	createcords(t_data *data);
void	ft_get_images(t_data *data, int img_width, int img_height);
int		ft_readinputs(t_data *data, char **argv);
char	**ft_mapdup(t_data *data, char **map);
void	ft_consolelog_map(t_data *data);
char	**ft_kill_player(t_data *data, char **map, int j, int i);
void	ft_player_death(t_data *data, int img_width, int img_height);
void	ft_check_enemy(t_data *data);
char	**ft_update_enemy(char **map, int j, int i);
void	ft_player_bob(t_data *data, int img_width, int img_height);
void	ft_update_move(int key, t_data *data);
void	ft_finish_game(int key, t_data *data);
void	if_bang_enemy(int key, t_data *data);
void	ft_count_items(int key, t_data *data);
int		ft_check_valid(t_data *data);
void	if_bang_enemy2(int key, t_data *data);
char	*ft_itoa(int n);
void	exit_game(t_data *data);

#endif