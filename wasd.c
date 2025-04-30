#include "cub3d.h"

void    key_w()
{
    double newX;
    double newY;

    newX = s()->p.X + s()->p.dirX * speed;
    newY = s()->p.Y + s()->p.dirY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)newX] != '1')//collision horizontale
        s()->p.X = newX;
    if (s()->map.data[(int)newY][(int)s()->p.X] != '1')//collision verticale
        s()->p.Y = newY;
}

void    key_s()
{
    double newX;
    double newY;

    newX = s()->p.X - s()->p.dirX * speed;
    newY = s()->p.Y - s()->p.dirY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)newX] != '1')
        s()->p.X = newX;
    if (s()->map.data[(int)newY][(int)s()->p.X] != '1')
        s()->p.Y = newY;
}

void    key_a()
{
    double newplaneX;
    double newplaneY;

    newplaneX = s()->p.X - s()->p.planeX * speed;
    newplaneY = s()->p.Y - s()->p.planeY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)newplaneX] != '1')
        s()->p.X = newplaneX;
    if (s()->map.data[(int)newplaneY][(int)s()->p.X] != '1')
        s()->p.Y = newplaneY;
}

void    key_d()
{
    double newplaneX;
    double newplaneY;

    newplaneX = s()->p.X + s()->p.planeX * speed;
    newplaneY = s()->p.Y + s()->p.planeY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)newplaneX] != '1')
        s()->p.X = newplaneX;
    if (s()->map.data[(int)newplaneY][(int)s()->p.X] != '1')
        s()->p.Y = newplaneY;
}