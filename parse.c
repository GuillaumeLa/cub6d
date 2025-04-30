#include "cub3d.h"
#include "get_next_line.h"

int parse_identifier(char *line , int identifier ,t_config *conf)
{
	char **rgb;

	if(identifier <= 5 && identifier >= 2)
	{
		if(!handle_files(line , conf , identifier))
			return (0);
	}
	else if(identifier == 6 || identifier == 7)
	{
		rgb = ft_split(line + 2, ',');
		if(!handle_rgb(identifier, conf, rgb))
			return (free(rgb),0);
		free(rgb);
	}
	free(line);
	return (1);
}

int find_identifier(char *line)
{
	if(ft_strlen(line) > 2)
	{
		if (line[0] == 'R' && line[1] == ' ')
			return (1);
		else if (line[0] == 'N' && line[1] == 'O')
			return (2);
		else if (line[0] == 'S' && line[1] == 'O')
			return (3);
		else if (line[0] == 'W' && line[1] == 'E')
			return (4);
		else if (line[0] == 'E' && line[1] == 'A')
			return (5);
		else if (line[0] == 'F')
			return (6);
		else if (line[0] == 'C')
			return (7);
	}
	return (0);
}

int parse_cub(char *filename)
{
	t_config *conf = s();

	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub\0", 5))
		return (0);
	if(!handle_map(filename))
		return (0);
	if(!handle_decals(filename ,conf))
		return (0);
	return (1);
}