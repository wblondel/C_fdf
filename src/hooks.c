/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:16:08 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 13:49:01 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void	set_hooks(t_view *v)
{
	mlx_do_key_autorepeaton(v->mlx);
	mlx_hook(v->window, 2, 0, key_press_hook, v);
	mlx_hook(v->window, 3, 0, key_release_hook, v);
	mlx_hook(v->window, 4, 0, mouse_press_hook, v);
	mlx_hook(v->window, 5, 0, mouse_release_hook, v);
	mlx_hook(v->window, 6, 0, motion_hook, v);
	mlx_hook(v->window, 17, 0, exit_hook, v);
}

int		key_press_hook(int keycode, t_view *v)
{
	key_toggle(&v->key, keycode, 1);

	if (v->key.esc)
	{
		mlx_destroy_window(v->mlx, v->window);
		exit(EXIT_SUCCESS);
	}

	if (v->key.d)
	{
		ft_putstr("Moving map to the left.\n");
		/*map_move(v, 0, 1, 0);*/
	}

	if (v->key.a)
	{
		ft_putstr("Moving map to the right.\n");
		/*map_move(v, 0, -1, 0);*/
	}

	if (v->key.w)
	{
		ft_putstr("Moving map down.\n");
		/*map_move(v, 0, 0, -1);*/
	}

	if (v->key.s)
	{
		ft_putstr("Moving map up.\n");
		/*map_move(v, 0, 0, 1);*/
	}
	return (0);
}

int		key_release_hook(int keycode, t_view *v)
{
	key_toggle(&v->key, keycode, 0);
	return (0);
}

int		mouse_press_hook(int keycode, int x, int y, t_view *v)
{
	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		click_toggle(&v->click, keycode, 1);
		v->mouse_x = x;
		v->mouse_y = y;
	}
	return (0);
}

int		mouse_release_hook(int keycode, int x, int y, t_view *v)
{
	click_toggle(&v->click, keycode, 0);

	v->mouse_x = x;
	v->mouse_y = y;
	return (0);
}

int		motion_hook(int x, int y, t_view *v)
{
	v->mouse_x = x;
	v->mouse_y = y;

	/* Cette partie doit se retrouver dans la fonction de creation d'image */

	/*if (v->mouse_x && v->mouse_y)
	{
		if (v->mouse_x > W_WIDTH || v->mouse_y > W_HEIGHT ||
			v->mouse_x < 0 || v->mouse_y < 0)
		{
			ft_putstr("click init");
			clicks_init(&v->click);
		}
		if (v->click.left)
		{
			if (v->mouse_x < x)
			{
				ft_putstr("Rotating anti-clockwise\n");
			}
			else if (v->mouse_x > x)
			{
				ft_putstr("Rotating clockwise\n");
			}
			v->mouse_x = x;
			v->mouse_y = y;
		}
	}*/
	return (0);
}

/*
** Refreshes the image.
** For now there is no FPS limit...
** So I think we basically use 100% of our CPU here.
** TODO: FPS limit.
*/
int		loop_hook(t_view *v)
{
	create_image(v->mlx, &v->image);
	render_map(v->image.pixels);
	mlx_put_image_to_window(v->mlx, v->window, v->image.ptr, 0, 0);
	mlx_destroy_image(v->mlx, v->image.ptr);
	/*ft_putstr("x: ");
	ft_putnbr(v->mouse_x);
	ft_putstr("; y: ");
	ft_putnbr(v->mouse_y);
	ft_putstr("\n");*/
	/*ft_putstr(*v->map.filelines);*/
	return (0);
}

/*
** Hook when we click the red cross.
** TODO: Call a function to free everything here.
*/
int		exit_hook(int keycode, t_view *v)
{
	(void)keycode;
	(void)v;
	exit(EXIT_SUCCESS);
}
