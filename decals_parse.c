#include "cub3d.h"
#include "get_next_line.h"

int handle_files(char *line , t_config *conf , int identifier)
{
	int fd;
	char *filename;

	filename = line + 3;
	size_t len = ft_strlen(filename);
	if (len > 0 && filename[len - 1] == '\n')
		filename[len - 1] = '\0';
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".xpm\0", 5))
		return (write(2,"Files must be .xpm\n",19),0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2,"a File can't open\n",18),0);
	if (identifier == 2)
		conf->decals.n.path = ft_strdup(filename);
	else if (identifier == 3)
		conf->decals.s.path = ft_strdup(filename);
	else if (identifier == 4)
		conf->decals.w.path = ft_strdup(filename);
	else if (identifier == 5)
		conf->decals.e.path = ft_strdup(filename);
	close(fd);
	return (1);
}
void set_rgb_color(t_color *color , int i , int number)
{
	if (i == 0)
		color->r = number;
	else if (i == 1)
		color->g = number;
	else if (i == 2)
		color->b = number;
}
int handle_rgb(int identifier , t_config *conf, char **rgb)
{
	int i = 0;
	int number;
	while(rgb[i])
	{
		if(ft_strlen(rgb[i]) > 11)
			return (write(2,"Incorrect format for RGB\n",25),0);
		number = ft_atoi(rgb[i]);
		if (number < 0 || number > 255)
			return (write(2,"Incorrect format for RGB\n",25),0);
		if (identifier == 6)
			set_rgb_color(&conf->decals.floor_color, i, number); 
		else if (identifier == 7)
			set_rgb_color(&conf->decals.ceiling_color, i, number); 
		free(rgb[i]);
		i++;
	}
	return (1);
}

int handle_decals(char *filename , t_config *conf)
{
	char *get_nextline;
	int identifier;
	int fd_decals;

	fd_decals = open(filename, O_RDONLY);
	if (fd_decals < 0)
		return (0);
	get_nextline = get_next_line(fd_decals);
	while (get_nextline)
	{
		identifier = find_identifier(get_nextline);
		if(identifier)
		{
			if(!parse_identifier(get_nextline , identifier , conf))
				return (free(get_nextline),0);
		}
		else
			break;
		get_nextline = get_next_line(fd_decals);
	}
	free(get_nextline);
	return 1;
}