#include "cub3d.h"

//modifie les pixels d'une img en memoire
//(alors que mlx_putpix regenere chaque pixel a chaque appel)
void put_pixel(int x, int y, int color, t_config *game)
{
    int index;

    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    index = y * game->size_line + x * game->bpp / 8;
    game->pixel_data[index] = color & 0xFF;
    game->pixel_data[index + 1] = (color >> 8) & 0xFF;
    game->pixel_data[index + 2] = (color >> 16) & 0xFF;
}

void print_playerv2()
{
	printf("(X %f, Y %f)\n", s()->p.X, s()->p.Y);
    printf("(dirX %f, dirY %f)\n", s()->p.dirX, s()->p.dirY);
    printf("(planeX %f, planeY %f)\n", s()->p.planeX, s()->p.planeY);
    printf("\n");
}

void clear_image(t_config *game)
{
    for(int y = 0; y < HEIGHT; y++)
        for(int x = 0; x < WIDTH; x++)
            put_pixel(x, y, 0, game);
}

int rgb_to_hex(t_color color) {
    return (color.r << 16) + (color.g << 8) + color.b;
}

void draw_vertical_line(int x, double distance, int orientation, double stepX, double stepY)
{
    int hauteur = (int)(HEIGHT / distance);
    int color;
    int tex_x;
    int tex_y;
    int hautDuMur = -hauteur / 2 + HEIGHT / 2;
    if (hautDuMur < 0)
        hautDuMur = 0;
    int basDuMur = hauteur / 2 + HEIGHT / 2;
    if (basDuMur >= HEIGHT)
        basDuMur = HEIGHT - 1;

    stepX += 0;
    stepY += 0;

    //amettredansleparsing
    s()->decals.floor_color = (t_color){255, 165, 0};
    s()->decals.ceiling_color = (t_color){255, 0, 0};

    //ciel
    for (int y = 0; y < hautDuMur; y++)
        put_pixel(x, y, rgb_to_hex(s()->decals.ceiling_color) , s());
    
    //mur
    for (int y = hautDuMur; y <= basDuMur; y++)
    {
        double wallHeight = (double)hauteur;
        double texturePos = (y - hautDuMur) / wallHeight;
        
        tex_x = (int)(orientation * s()->t[0].w) % s()->t[0].w;
        tex_y = (int)(texturePos * s()->t[0].h) % s()->t[0].h;
        
        color = s()->t[0].addr[tex_y * s()->t[0].w + tex_x];
        
        put_pixel(x, y, color, s());  
    }
        
    //sol
    for (int y = basDuMur; y < HEIGHT; y++)
        put_pixel(x, y, rgb_to_hex(s()->decals.floor_color) , s());
    
    printf("color : %d\n", color);
    // printf("floor_color : %d\n", rgb_to_hex(s()->decals.floor_color));
}

//pr chaque colonne x de la largeur de l'ecran
void cast_ray(int x)
{
    double cameraX = 2 * x / (double)WIDTH - 1;
    double rayDirX = s()->p.dirX + s()->p.planeX * cameraX;
    double rayDirY = s()->p.dirY + s()->p.planeY * cameraX;
    int mapX = (int)s()->p.X;
    int mapY = (int)s()->p.Y;
    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);
    double sideDistX, sideDistY;
    int stepX, stepY;
    double distance;
    double orientation;
    int hit;

    //initialisation DDA
    if (rayDirX < 0)
    {
        stepX = -1;
        sideDistX = (s()->p.X - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - s()->p.X) * deltaDistX;
    }
    if (rayDirY < 0)
    {
        stepY = -1;
        sideDistY = (s()->p.Y - mapY) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - s()->p.Y) * deltaDistY;
    }

    //algo DDA
    hit = 0;
    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            orientation = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            orientation = 1;
        }
        if(mapX < 0 || mapX >= s()->map.line || mapY < 0 || mapY >= s()->map.columns)
            break;
        if (s()->map.data[mapX][mapY])
        {
            if(s()->map.data[mapX][mapY] == '1')
                hit = 1;
        }

    }

    if (orientation == 0)
        distance = (mapX - s()->p.X + (1 - stepX) / 2) / rayDirX;
    else
        distance = (mapY - s()->p.Y + (1 - stepY) / 2) / rayDirY;

    draw_vertical_line(x, distance, orientation, stepX, stepY);
}

int raycasting()
{
    // print_playerv2();
    clear_image(s());
    for (int x = 0; x < WIDTH; x++)
        cast_ray(x);
    mlx_put_image_to_window(s()->mlx, s()->win, s()->img, 0,0);
    return 0;
}

