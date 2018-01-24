/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_others.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:32:52 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 13:46:51 by wblondel    ###    #+. /#+    ###.fr     */
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

int		motion_hook(int x, int y, t_global *g)
{
	g->mouse.x = x;
	g->mouse.y = y;
	return (0);
}

/*
** Refreshes the image.
** For now there is no FPS limit...
** So I think we basically use 100% of our CPU here.
** TODO: FPS limit.
*/

int		loop_hook(t_global *g)
{
	/*if ( (int)time(NULL) >= g->timestamp_lastrefresh + 1)
	{
		printf("Redrawing.\n");*/
		mlx_create_image(g->mlx, &g->image);
		calculate_points(&g->map, &g->cam);
		draw_map(g->image.pixels, g->map.points, &g->map);
		mlx_put_image_to_window(g->mlx, g->window, g->image.ptr, 0, 0);
		draw_ui(g);
		mlx_destroy_image(g->mlx, g->image.ptr);
		/*g->timestamp_lastrefresh = (int)time(NULL);
	}*/
	return (0);
}

/*
** Hook when we click the red cross.
** TODO: Call a function to free everything here.
*/

int		exit_hook(int keycode, t_global *g)
{
	(void)keycode;
	(void)g;
	exit(EXIT_SUCCESS);
}
