#include "cub3d.h"

int close_window_echap()
{
    mlx_destroy_window(s()->mlx, s()->win);
    mlx_destroy_display(s()->mlx);//detruit la connexion a mlx
    free(s()->mlx);
    exit(0);
    return 0;
}

int close_window_cross()
{
    mlx_destroy_window(s()->mlx, s()->win);
    mlx_destroy_display(s()->mlx);
    free(s()->mlx);
    exit(0);
}

int key_press(int touche)
{
    if (touche == W)
        s()->k.w = 1;
    else if (touche == S)
        s()->k.s = 1;
    else if (touche == D)
        s()->k.d = 1;
    else if (touche == A)
        s()->k.a = 1;
    else if (touche == R)
        s()->k.r = 1;
    else if (touche == L)
        s()->k.l = 1;
    else if (touche == ECHAP)
        close_window_echap();
    return 0;
}

int key_release(int touche)
{
    if (touche == W)
        s()->k.w = 0;
    else if (touche == S)
        s()->k.s = 0;
    else if (touche == D)
        s()->k.d = 0;
    else if (touche == A)
        s()->k.a = 0;
    else if (touche == R)
        s()->k.r = 0;
    else if (touche == L)
        s()->k.l = 0;
    return 0;
}

int game_loop()
{
    // mlx_clear_window(s()->mlx, s()->win);
	if (s()->k.w)
		key_w();
	if (s()->k.s)
        key_s();
	if (s()->k.a)
        key_a();
	if (s()->k.d)
        key_d();
	if (s()->k.l)
        key_L();
    if (s()->k.r)
        key_R();

    raycasting(s());
    return (0);
}