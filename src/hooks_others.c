/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_others.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:32:52 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 20:35:53 by wblondel    ###    #+. /#+    ###.fr     */
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
	/*if ( (int)time(NULL) >= v->timestamp_lastrefresh + 1)
	{*/
		/*printf("Redrawing.\n");*/
		create_image(v->mlx, &v->image);
		calculate_points(&v->map);
		render_map(v->image.pixels, v->map.points, &v->map);
		mlx_put_image_to_window(v->mlx, v->window, v->image.ptr, 0, 0);

		mlx_string_put(v->mlx, v->window, 10, 570, 0xFFFFFF, "Scale:");
		mlx_string_put(v->mlx, v->window, 80, 570, 0xFFFFFF, ft_itoa(v->map.scale));
		mlx_string_put(v->mlx, v->window, 120, 570, 0xFFFFFF, "Margin X:");
		mlx_string_put(v->mlx, v->window, 220, 570, 0xFFFFFF, ft_itoa(v->map.margin_x));
		mlx_string_put(v->mlx, v->window, 260, 570, 0xFFFFFF, "Margin Y:");
		mlx_string_put(v->mlx, v->window, 360, 570, 0xFFFFFF, ft_itoa(v->map.margin_y));

		mlx_destroy_image(v->mlx, v->image.ptr);
		v->timestamp_lastrefresh = (int)time(NULL);
	/*}*/
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
