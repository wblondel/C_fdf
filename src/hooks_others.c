/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_others.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:32:52 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 20:52:05 by wblondel    ###    #+. /#+    ###.fr     */
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

/*
** It looks like the minilibx limits the FPS to 60.
** Good.
*/

int		loop_hook(t_global *g)
{
	mlx_create_image(g->mlx, &g->image);
	calculate_points(&g->map, &g->cam);
	draw_map(g->image.pixels, g->map.points, &g->map);
	mlx_put_image_to_window(g->mlx, g->window, g->image.ptr, 0, 0);
	draw_ui(g);
	mlx_destroy_image(g->mlx, g->image.ptr);
	return (0);
}

/*
** Hook when we click the red cross.
**
** You are correct, no harm is done and it's faster to just exit
** There are various reasons for this:
** All desktop and server environments simply release the entire memory space on
** exit(). They are unaware of program-internal data structures such as heaps.
** Almost all free() implementations do not ever return memory to the operating
** system anyway. More importantly, it's a waste of time when done right before
** exit(). At exit, memory pages and swap space are simply released. By
** contrast, a series of free() calls will burn CPU time and can result in disk
** paging operations, cache misses, and cache evictions.
*/

int		exit_hook(int keycode, t_global *g)
{
	(void)g;
	(void)keycode;
	/*int i;

	i = 0;*/
	/*if (keycode == KEY_ESC)
	{
		mlx_destroy_window(g->mlx, g->window);
		free(g->mlx);
		if (g->map.points)
			free(g->map.points);
		while (i < g->map.height)
		{
			free(g->map.file[i]);
			i++;
		}
		free(g);
	}*/
	exit(EXIT_SUCCESS);
}
