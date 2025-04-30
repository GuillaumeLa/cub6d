#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * 6); // 5 lignes + NULL

    if (!map)
        return NULL;

    map[0] = strdup("111111");
    map[1] = strdup("100001");
    map[2] = strdup("100011");
    map[3] = strdup("10N001");
    map[4] = strdup("111111");
    map[5] = NULL; // Marqueur de fin

    return map;
}

void print_map(char **map)
{
    printf(BOLD GREEN"---------- MAP (apres init_map) ----------\n"RESET);
    int i = 0;
    while (map && map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    printf("\n");
}

int map_lines(char **map)
{
    int count = 0;
    while (map && map[count])
        count++;
    return count;
}


int map_columns(char **map)
{
    int i = 0;
    int max = 0;
    while (map && map[i])
    {
        int len = strlen(map[i]);
        if (len > max)
            max = len;
        i++;
    }
    return max;
}

int parsing()
{
    s()->map.data = init_map();
	s()->map.line = map_lines(s()->map.data);
	s()->map.columns = map_columns(s()->map.data);
    char **tmp = s()->map.data;
    print_map(tmp);
    s()->decals.n.path = "test_decals/collectible.xpm";
    s()->decals.s.path = "test_decals/exit.xpm";
    s()->decals.e.path = "test_decals/grass.xpm";
    s()->decals.w.path = "test_decals/haies.xpm";
    return (1);
}