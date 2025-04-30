#ifndef CUB3D_H
# define CUB3D_H

# include "includes/libft/libft.h"
# include "includes/mlx/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define NAME "CUB3D"
# define WIDTH 1280
# define HEIGHT 720
# define TILE_SIZE 20
# define DEBUG 0
# define ECHAP 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define L 65361
# define R 65363
# define speed 0.01
# define rot_speed 0.01

#define BOLD "\033[1m"
#define RED "\033[38;2;255;0;0m"
#define GREEN "\033[38;2;0;255;0m"
#define RESET "\033[0m"

typedef struct s_player
{
    double X;
    double Y;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
} t_player;

typedef struct s_texture
{
    void *img;
    char *path;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int w;
    int h;
} t_texture ;

typedef struct s_color {
    int r;
    int g;
    int b;
} t_color;

typedef struct s_map
{
    int line;
    int columns;
    char **data;
} t_map;

typedef struct s_decals {
    t_texture n;
    t_texture s;
    t_texture w;
    t_texture e;
    t_color     floor_color;
    t_color     ceiling_color;
} t_decals;

typedef struct s_keys
{
    int w;
    int s;
    int d;
    int a;
    int r;
    int l;
} t_keys;

typedef struct s_config
{
    void    *mlx;
    void    *win;
    void   *img;
    char    *pixel_data;
    int bpp;
    int size_line;
    int endian;
    t_map    map;
    t_decals decals;
    t_texture   *t;
    t_texture   screen;
    t_player p;
    t_keys      k;
} t_config;

//parsing
int     handle_map(char *filename);
int     parse_cub(char *filename);
int     handle_decals(char *filename , t_config *conf);
int     handle_rgb(int identifier , t_config *conf, char **rgb);
int     handle_files(char *line , t_config *conf , int identifier);
int     find_identifier(char *line);
int     parse_identifier(char *line , int identifier ,t_config *conf);

//deplacement (wasd.c rotations.c)
void    key_w();
void    key_s();
void    key_a();
void    key_d();
void    key_R();
void    key_L();

//display (init, esc, red cross, gestion du clavier)
void open_window();
int close_window_cross();
int close_window_echap();
int key_press(int touche);
int key_release(int touche);
int game_loop();
void init_player(void);
void init_game();
void    init_tex();
void free_textures();

//raycasting
int     raytracing(t_config *game);
int raycasting();

//utils
t_config	*s(void);
//free
void free_map();
void free_textures();

//test 
char **init_map(void);
void print_map(char **map);
// void free_map(char **map);
int count_lines(char **map);
int count_max_columns(char **map);
int parsing();
void print_playerv2();
void put_pixel2(t_texture *img, int x, int y, unsigned int color);

#endif