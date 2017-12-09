/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:16:08 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 11:41:12 by wblondel    ###    #+. /#+    ###.fr     */
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
	ft_putstr("Pressed. ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(v->mlx, v->window);
		exit(EXIT_SUCCESS);
	}
	key_toggle(&v->key, keycode, 1);
	return (0);
}

int		key_release_hook(int keycode, t_view *v)
{
	key_toggle(&v->key, keycode, 0);
	return (0);
}

int		motion_hook(int x, int y, t_view *v)
{
	if(v->mouse_x && v->mouse_y)
	{
		if (v->mouse_x < x)
			ft_putstr("Rotating anti-clockwise\n");
		else if (v->mouse_x > x)
			ft_putstr("Rotating clockwise\n");
		v->mouse_x = x;
		v->mouse_y = y;
	}
	return (0);
}

int		mouse_press_hook(int keycode, int x, int y, t_view *v)
{
	key_toggle(&v->key, keycode, 1);

	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		ft_putstr("Clicked.");
		ft_putnbr(keycode);
		ft_putchar('\n');
		v->mouse_x = x;
		v->mouse_y = y;
	}
	return (0);
}

int		mouse_release_hook(int keycode, int x, int y, t_view *v)
{
	key_toggle(&v->key, keycode, 0);
	(void)x;
	(void)y;
	ft_putstr("Released. ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	v->mouse_x = 0;
	v->mouse_y = 0;
	return (0);
}

int		loop_hook(t_view *v)
{
	create_image(v->mlx, &v->image);
	render_horizontal_lines(v->image.pixels);
	mlx_put_image_to_window(v->mlx, v->window, v->image.ptr, 0, 0);
	mlx_destroy_image(v->mlx, v->image.ptr);
	return (0);
}

int		exit_hook(int keycode, t_view *v)
{
	(void)keycode;
	(void)v;
	exit(EXIT_SUCCESS);
}
