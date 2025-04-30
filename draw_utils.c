#include "cub3d.h"

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

float corrected_distance(t_player player, float ray_x, float ray_y, float ray_angle)
{
    float dx;
    float dy;
    float dist;

    dx = ray_x - player.x * TILE_SIZE;
    dy = ray_y - player.y * TILE_SIZE;
    dist = sqrt(dx * dx + dy * dy);
    return dist * cos(ray_angle - player.angle);
}

void ft_clear()
{
    int y = 0;
    int x = 0;
    while(y < HEIGHT)
    {
        while(x < WIDTH)
        {
            put_pixel(x, y, 0x00000000, s());
            x++;
        }
        y++;
    }    
}

int has_touched_a_wall(float px, float py, t_config *game)
{
    int x = px / TILE_SIZE;
    int y = py / TILE_SIZE;
    if(game->map.data[y][x] == '1')
        return 1;
    return 0;
}

void print_line(t_player player, t_config *game, float ray_angle, int col)
{
    float ray_x;
    float ray_y;
    float dist;
    float wall_height;

    ray_x = player.x * TILE_SIZE;
    ray_y = player.y * TILE_SIZE + TILE_SIZE / 2;
    while (!has_touched_a_wall(ray_x, ray_y, game))
    {
        ray_x += cos(ray_angle) * 0.5;
        ray_y += sin(ray_angle) * 0.5;
    }
    dist = corrected_distance(player, ray_x, ray_y, ray_angle);
    wall_height = (TILE_SIZE / dist) * (WIDTH / 2);
    int start = (HEIGHT - wall_height) / 2;
    int end = start + wall_height;
    int y = start;
    while (y < end)
    {
        if (y >= 0 && y < HEIGHT)
            put_pixel(col, y, 0x00339999, game); 
        y++;
    }

}

void print_player()
{
	printf("(X %f, Y %f)\n", s()->p.X, s()->p.Y);
    printf("(dirX %f, dirY %f)\n", s()->p.dirX, s()->p.dirY);
    printf("(planeX %f, planeY %f)\n", s()->p.planeX, s()->p.planeY);
	printf("angle %f\n", s()->p.angle);
    printf("\n");
}

int raytracing(t_config *game)
{
    t_player player = game->p;
    float fov = M_PI / 2;
    float angle = player.angle - fov / 2; 
    float step = fov / WIDTH; 
    int i = 0;

    print_player();
    ft_clear();
    while (i < WIDTH)
    {
        print_line(player, game, angle, i);
        angle += step;
        i++;
    }
    mlx_put_image_to_window(s()->mlx, s()->win, s()->img, 0, 0);
    return 0;
}
