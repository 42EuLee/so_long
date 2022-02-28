#include "./includes/so_long.h"

int	ft_get_height(t_data *data, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || ft_strlen(line) == 1)
			break ;
		data->map_h++;
		free(line);
	}
	return (data->map_h);
}

void	ft_checksame_len(t_data *data, int i, char *line)
{
	int	count;

	count = 0;
	count = ft_strlen(line);
	if ((data->map_w != count) && (i > 1))
		return_error();
	data->map_w = count;
}

void	ft_read_error(char *line)
{
	free(line);
	line = NULL;
	return_error();
}

int	ft_readinputs(t_data *data, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	data->map = (char **)malloc(sizeof(char *) * ft_get_height(data, argv) + 1);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line)
		{
			ft_checksame_len(data, i, line);
			data->map[i++] = ft_strndup(line, data->map_w);
		}
		else
			ft_read_error(line);
		free(line);
	}
	if (ft_check_valid(data) == 0)
		return_error();
	return (1);
}
