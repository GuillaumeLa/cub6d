#include "cub3d.h"

//formules des rotations 2D:
//x' = x * cos(θ) - y * sin(θ)
//y' = x * sin(θ) + y * cos(θ)
void    key_L()
{
    double old_dirX;
    double old_planeX;

    old_dirX = s()->p.dirX;
    old_planeX = s()->p.planeX;

    //changement de direction
    s()->p.dirX = s()->p.dirX * cos(-rot_speed) - s()->p.dirY * sin(-rot_speed);
    s()->p.dirY = old_dirX * sin(-rot_speed) + s()->p.dirY * cos(-rot_speed);
    //changement de plan de la camera
    s()->p.planeX = s()->p.planeX * cos(-rot_speed) - s()->p.planeY * sin(-rot_speed);
    s()->p.planeY = old_planeX * sin(-rot_speed) + s()->p.planeY * cos(-rot_speed);
}

void    key_R()
{
    double old_dirX;
    double old_planeX;

    old_dirX = s()->p.dirX;
    old_planeX = s()->p.planeX;

    //changement de direction
    s()->p.dirX = s()->p.dirX * cos(rot_speed) - s()->p.dirY * sin(rot_speed);
    s()->p.dirY = old_dirX * sin(rot_speed) + s()->p.dirY * cos(rot_speed);
    //changement de plan de la camera
    s()->p.planeX = s()->p.planeX * cos(rot_speed) - s()->p.planeY * sin(rot_speed);
    s()->p.planeY = old_planeX * sin(rot_speed) + s()->p.planeY * cos(rot_speed);
}