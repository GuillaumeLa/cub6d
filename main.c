#include "cub3d.h"

int main(int argc , char *argv[])
{
	(void)argv;
	 (void)argc;
	// if(argc != 2)
	// 	return (write(2,"Error // Wrong number of arguments\n", 35), 1);
	// if(!parse_cub(argv[1]))
	// 	return (write(2,"Error // Invalid .cub file\n", 27), 1);
	// if (parsing())
	// {
	parsing();
	init_player();
	init_game();
	// }
	free_map();
	free_textures();
	return (0);
}