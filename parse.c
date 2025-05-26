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

#include "cub3d.h"
#include "get_next_line.h"

int parse_cub(char *filename)
{
    t_config *conf = s();

    printf(BOLD GREEN"---------- PARSE CUB ----------\n"RESET);

    if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub\0", 5)) {
        printf(RED"Error: Invalid file extension. Expected .cub\n"RESET);
        return (0);
    }
    printf(GREEN"File extension is valid: %s\n"RESET, filename);

    if (!handle_map(filename)) {
        printf(RED"Error: Failed to handle map\n"RESET);
        return (0);
    }
    printf(GREEN"Map successfully parsed:\n"RESET);
    for (int i = 0; i < conf->map.line; i++) {
        printf("Line %d: %s\n", i, conf->map.data[i]);
    }
    printf("Map dimensions: %d lines, %d columns\n", conf->map.line, conf->map.columns);

    if (!handle_decals(filename, conf)) {
        printf(RED"Error: Failed to handle decals\n"RESET);
        return (0);
    }
    printf(GREEN"Decals successfully parsed:\n"RESET);
    printf("North texture: %s\n", conf->decals.n.path);
    printf("South texture: %s\n", conf->decals.s.path);
    printf("East texture: %s\n", conf->decals.e.path);
    printf("West texture: %s\n", conf->decals.w.path);
    printf("Floor color: R=%d, G=%d, B=%d\n", conf->decals.floor_color.r, conf->decals.floor_color.g, conf->decals.floor_color.b);
    printf("Ceiling color: R=%d, G=%d, B=%d\n", conf->decals.ceiling_color.r, conf->decals.ceiling_color.g, conf->decals.ceiling_color.b);

    printf(GREEN"---------- PARSE CUB COMPLETE ----------\n"RESET);
    return (1);
}

// int parse_cub(char *filename)
// {
// 	t_config *conf = s();

// 	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub\0", 5))
// 		return (0);
// 	if(!handle_map(filename))
// 		return (0);
// 	if(!handle_decals(filename ,conf))
// 		return (0);
// 	return (1);
// }