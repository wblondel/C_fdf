/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_others.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:32:52 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 16:37:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Cette partie doit se retrouver dans la fonction de creation d'image
**if (v->mouse_x && v->mouse_y)
**{
**	if (v->mouse_x > W_WIDTH || v->mouse_y > W_HEIGHT ||
**		v->mouse_x < 0 || v->mouse_y < 0)
**	{
**		clicks_init(&v->click);
**	}
**	if (v->click.left)
**	{
**		if (v->mouse_x < x)
**			ft_putstr("Rotating anti-clockwise\n");
**		else if (v->mouse_x > x)
**			ft_putstr("Rotating clockwise\n");
**		v->mouse_x = x;
**		v->mouse_y = y;
**	}
**}
*/

int		motion_hook(int x, int y, t_view *v)
{
	v->mouse_x = x;
	v->mouse_y = y;
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
