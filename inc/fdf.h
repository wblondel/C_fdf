/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:54:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 17:27:41 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

/*
** Includes
*/
# include "basics/memory.h"
# include "basics/chars.h"
# include "basics/strings.h"
# include "basics/numbers.h"
# include "utils/file.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "keys.h"
# include "clicks.h"

# include <time.h>
# include <stdint.h>

/*
** Constants
*/
# define W_WIDTH 1920
# define W_HEIGHT 1080

/*
** Macros
*/
# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))
# define DEGTORAD(angleDegrees) ((angleDegrees) * M_PI / 180.0)
# define RADTODEG(angleRadians) ((angleRadians) * 180.0 / M_PI)

/*
** Structs
*/

/*
** Position of the cursor.
*/

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

/*
** margin_x and margin_y are the position where I start to draw.
** scale is the zoom: if scale = 10, the distance between two points will be 10.
*/

typedef struct		s_cam
{
	int				margin_x;
	int				margin_y;
	unsigned char	scale;
	float			height_multiplicator;
}					t_cam;

/*
** I read x, y, z from the file and store them in a s_point.
** Data are not changed when I draw the pixel. New x, y are calculated
** on the fly.
*/

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

/*
** Here is where I store the data of our height map.
** width (x) and height (y) are the number of points in the corresponding axis.
** file is a where I store the z value of each point.
** points is where I store the calculated x, y, z of each point.
*/

typedef struct		s_map
{
	int				width;
	int				height;
	int				depth_min;
	int				depth_max;
	int				**file;
	t_point			*points;
}					t_map;

/*
** Here is where our image is stored.
** ptr is created with mlx_new_image(mlx, W_WIDTH, W_HEIGHT)
** pixels is created with (int *)mlx_get_data_addr(image->ptr,
**				&image->bits_per_pixel, &image->size_line, &image->endian)
*/

typedef struct		s_img
{
	void			*ptr;
	int				*pixels;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

}					t_img;

typedef struct		s_global
{
	void			*mlx;
	void			*window;
	t_img			image;
	t_map			map;
	t_cam			cam;
	t_keys			key;
	t_clicks		click;
	t_mouse			mouse;
	int64_t			ts_mlx_create_image_start;
	int64_t			ts_mlx_create_image_end;
	int64_t			ts_calculate_points_start;
	int64_t			ts_calculate_points_end;
	int64_t			ts_draw_map_start;
	int64_t			ts_draw_map_end;
	int64_t			ts_mlx_put_image_to_window_start;
	int64_t			ts_mlx_put_image_to_window_end;
}					t_global;

/*
** calculate.c
*/
void				to_isometric_2d(t_point *point);
void				calculate_points(t_map *map, t_cam *cam);

/*
** cam.c
*/
void				cam_set_margin(t_cam *cam, int x, int y);
void				cam_set_scale(t_cam *cam, int scale);

/*
** clicks.c
*/
void				clicks_init(t_clicks *click);
void				click_toggle(t_clicks *click, int keycode, int toggle);

/*
** debug.c
*/
void				print_map(t_map *map);
void				print_points(t_map *map);

/*
** draw_map.c
*/
int					draw_pixel(int y, int x, int *pixels);
void				draw_line(t_point point0, t_point point1, int *pixels);
void				draw_lines(int *pixels, t_point *points, t_map *map);
void				draw_points(int *pixels, t_point *points, t_map *map);
void				draw_map(int *pixels, t_point *points, t_map *map);

/*
** draw_ui.c
*/
void				draw_ui(t_global *g);
void				draw_ui2(t_global *g);

/*
** hooks_init.c
*/
void				set_hooks(t_global *g);

/*
** hooks_keyboard.c
*/
int					key_press_hook(int keycode, t_global *g);
int					key_release_hook(int keycode, t_global *g);

/*
** hooks_mouse.c
*/
int					mouse_press_hook(int keycode, int x, int y, t_global *g);
int					mouse_release_hook(int keycode, int x, int y, t_global *g);
int					motion_hook(int x, int y, t_global *g);

/*
** hooks_others.c
*/
int					loop_hook(t_global *g);
int					exit_hook(int keycode, t_global *g);

/*
** image.c
*/
void				mlx_create_image(void *mlx, t_img *image);

/*
** import.c
*/
int					import_from_file(char const *filename, t_map *map);

/*
** init.c
*/
t_global			*init_global(void);

/*
** keys.c
*/
void				keys_init(t_keys *key);
void				key_toggle(t_keys *key, int keycode, int toggle);

/*
** main.c
*/
void				error(char *msg);

#endif
