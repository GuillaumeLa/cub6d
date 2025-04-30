#include "cub3d.h"

void free_map()
{
    int i = 0;
    if (!s()->map.data)
        return;
    while (s()->map.data[i])
    {
        free(s()->map.data[i]);
        i++;
    }
    free(s()->map.data);
}

void free_textures()
{
    for (int i = 0; i < 4; i++)
    {
        if (s()->t[i].img)
        {
            mlx_destroy_image(s()->mlx, s()->t[i].img);
            s()->t[i].img = NULL;
        }
    }
}