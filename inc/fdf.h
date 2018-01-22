/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:54:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 14:44:33 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

/*
** Includes
*/
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include "clicks.h"

/*
** Constants
*/
# define W_WIDTH 600
# define W_HEIGHT 600

/*
** Structs
*/

typedef struct		s_point
{
	int 		x;
	int			y;
	int z;
}					t_point;

typedef struct		s_map
{
	int				width;
	int				height;
	int				depth_min;
	int				depth_max;
	int				**file;
}					t_map;

typedef struct		s_img
{
	void			*ptr;
	int				*pixels;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_view
{
	void			*mlx;
	void			*window;
	t_img			image;
	t_map			map;
	t_keys			key;
	t_clicks		click;
	int				mouse_x;
	int				mouse_y;
}					t_view;

/*
** clicks.c
*/
void				clicks_init(t_clicks *click);
void				click_toggle(t_clicks *click, int keycode, int toggle);

/*
** debug.c
*/
void 				print_map(t_map *map);

/*
** hooks_init.c
*/
void				set_hooks(t_view *v);

/*
** hooks_keyboard.c
*/
int					key_press_hook(int keycode, t_view *v);
int					key_release_hook(int keycode, t_view *v);

/*
** hooks_mouse.c
*/
int					mouse_press_hook(int keycode, int x, int y, t_view *v);
int					mouse_release_hook(int keycode, int x, int y, t_view *v);
int					motion_hook(int x, int y, t_view *v);

/*
** hooks_others.c
*/
int					loop_hook(t_view *v);
int					exit_hook(int keycode, t_view *v);

/*
** image.c
*/
void				create_image(void *mlx, t_img *image);

/*
** import.c
*/
int					import_from_file(char const *filename, t_map *map);

/*
** init.c
*/
t_view				*init_view(void);

/*
** keys.c
*/
void				keys_init(t_keys *key);
void				key_toggle(t_keys *key, int keycode, int toggle);

/*
** main.c
*/
void				error(char *msg);

/*
** map.c
*/
void				fill_map(t_map *map, t_list *l);

/*
** render.c
*/
void				render_map(int *pixels);

#endif
