#include "cub3d.h"

void    init_tex()
{
	//amettredansleparsing
	printf(BOLD"~ INIT TEXTURES ~\n"RESET);
	s()->t = malloc(sizeof(t_texture) * 4);
	s()->t[0].path = s()->decals.n.path;
    s()->t[1].path = s()->decals.s.path;
    s()->t[2].path = s()->decals.e.path;
    s()->t[3].path = s()->decals.w.path;

    for (int i = 0; i < 4; i++)
    {
		printf("path to tx[%d] : %s\n", i, s()->t[i].path);
		//charger les textures
        s()->t[i].img = mlx_xpm_file_to_image(s()->mlx, s()->t[i].path, &s()->t[i].w, &s()->t[i].h);
        if (!s()->t[i].img)
			return;
		//pointeur vers donnees des pixels
		s()->t[i].addr = mlx_get_data_addr(s()->t[i].img, &s()->t[i].bpp, &s()->t[i].line_len, &s()->t[i].endian);
		if (!s()->t[i].addr)
			return;
    }
	printf(BOLD"init img n addr ok\n"RESET);
	printf("\n");
}

void init_player(void)
{
	printf(BOLD GREEN"---------- INIT PLAYER ----------\n"RESET);
	for (int y = 0; y < s()->map.line; y++)
	{
		for (int x = 0; x < s()->map.columns; x++)
		{
			char c = s()->map.data[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				printf("x et y : %d %d\n", x, y);
				printf("char c : %c\n", c);
				s()->p.X = x;
				s()->p.Y = y;
				if (c == 'N')
				{
					s()->p.dirX = 0;
					s()->p.dirY = -1;
					s()->p.planeX = 0.66;
					s()->p.planeY = 0.0;
				}
				if (c == 'S') 
				{
					s()->p.dirX = 0;
					s()->p.dirY = 1;
					s()->p.planeX = -0.66;
					s()->p.planeY = 0.0;
				}
				if (c == 'E') {
					s()->p.dirX = 1;
					s()->p.dirY = 0;
					s()->p.planeX = 0.0;
					s()->p.planeY = 0.66;
				}
				if (c == 'W') {
					s()->p.dirX = -1;
					s()->p.dirY = 0;
					s()->p.planeX = 0.0;
					s()->p.planeY = -0.66;
				}
			}
		}
	}
	print_playerv2();
	return;
}

void init_game()
{
	printf(BOLD GREEN"---------- INIT GAME ----------\n"RESET);
    s()->mlx = mlx_init();
	if (s()->mlx == NULL)
		return;
    s()->win = mlx_new_window(s()->mlx, WIDTH, HEIGHT, NAME);
    if (s()->win == NULL)
		return;
	init_tex();
	s()->img = mlx_new_image(s()->mlx, WIDTH, HEIGHT);
    s()->pixel_data = mlx_get_data_addr(s()->img, &s()->bpp, &s()->size_line, &s()->endian);
	mlx_put_image_to_window(s()->mlx, s()->win, s()->img, 0, 0);
	mlx_hook(s()->win, 17, 0L, close_window_cross, NULL);//17 = fermeture de la fenetre
    mlx_hook(s()->win, 2, 1L<<0, key_press, NULL);//2 = keypress
    mlx_hook(s()->win, 3, 1L<<1, key_release, NULL);//3 = keyrelease
    mlx_loop_hook(s()->mlx, game_loop, NULL);
    mlx_loop(s()->mlx);
}